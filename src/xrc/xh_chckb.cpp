/////////////////////////////////////////////////////////////////////////////
// Name:        xh_chckb.cpp
// Purpose:     XRC resource for wxCheckBox
// Author:      Bob Mitchell
// Created:     2000/03/21
// RCS-ID:      $Id$
// Copyright:   (c) 2000 Bob Mitchell and Verant Interactive
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
#pragma implementation "xh_chckb.h"
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#if wxUSE_XRC && wxUSE_CHECKBOX

#include "wx/xrc/xh_chckb.h"
#include "wx/checkbox.h"

IMPLEMENT_DYNAMIC_CLASS(wxCheckBoxXmlHandler, wxXmlResourceHandler)

wxCheckBoxXmlHandler::wxCheckBoxXmlHandler()
: wxXmlResourceHandler()
{
    XRC_ADD_STYLE(wxCHK_2STATE);
    XRC_ADD_STYLE(wxCHK_3STATE);
    XRC_ADD_STYLE(wxCHK_ALLOW_3RD_STATE_FOR_USER);
    XRC_ADD_STYLE(wxALIGN_RIGHT);
    AddWindowStyles();
}

wxObject *wxCheckBoxXmlHandler::DoCreateResource()
{
    XRC_MAKE_INSTANCE(control, wxCheckBox)

    control->Create(m_parentAsWindow,
                    GetID(),
                    GetText(wxT("label")),
                    GetPosition(), GetSize(),
                    GetStyle(),
                    wxDefaultValidator,
                    GetName());

    control->SetValue(GetBool( wxT("checked")));
    SetupWindow(control);

    return control;
}

bool wxCheckBoxXmlHandler::CanHandle(wxXmlNode *node)
{
    return IsOfClass(node, wxT("wxCheckBox"));
}

#endif // wxUSE_XRC && wxUSE_CHECKBOX
