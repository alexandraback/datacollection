#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys

dic={'a':'y',
'b':'h',
'c':'e',
'd':'s',
'e':'o',
'f':'c',
'g':'v',
'h':'x',
'i':'d',
'j':'u',
'k':'i',
'l':'g',
'm':'l',
'n':'b',
'o':'k',
'p':'r',
'q':'z',
'r':'t',
's':'n',
't':'w',
'u':'j',
'v':'p',
'w':'f',
'x':'m',
'y':'a',
'z':'q',
' ':' '}

lines=int(sys.stdin.readline().strip())

for i in range(lines):
    instr=sys.stdin.readline().strip()
    outstr=""
    for j,x in enumerate(instr):
        outstr+=dic[x]
    print "Case #%d: %s" % (i+1, outstr)

