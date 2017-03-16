#! /usr/bin/env python
#-*- coding: utf-8 -*-
import sys,requests,json,os,traceback,datetime
reload(sys)
sys.setdefaultencoding('utf8')

T = int(raw_input())
for Case in range(1, T+1):
    print "Case #%d: " % Case,
    s = raw_input()
    ans = ""
    for c in s:
        a = ans + c
        b = c + ans
        if a > b:
            ans = a
        else:
            ans = b
    print ans
