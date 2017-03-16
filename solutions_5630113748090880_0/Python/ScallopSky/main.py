#! /usr/bin/env python
#-*- coding: utf-8 -*-
import sys,requests,json,os,traceback,datetime
reload(sys)
sys.setdefaultencoding('utf8')

def add(x):
    global cnt
    cnt[int(x)]+=1

cnt = None

T = int(raw_input())
for Case in range(1, T+1):
    print "Case #%d:" % Case,
    n = int(raw_input())
    m = 2*n-1
    cnt = [ 0 for i in range(2600) ]
    a = [ map(add, raw_input().split(' ')) for i in range(m) ]

    print " ".join([ str(i) for (i, v) in enumerate(cnt) if v%2==1 ])
