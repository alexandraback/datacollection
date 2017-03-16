#! /usr/bin/env python
#-*- coding: utf-8 -*-
import sys,requests,json,os,traceback,datetime
reload(sys)
sys.setdefaultencoding('utf8')

T = int(raw_input())
for Case in range(1, T+1):
    print "Case #%d: " % Case,
    n = int(raw_input())
    if n == 0:
        print "INSOMNIA"
        continue
    flag = []
    for i in range(10):
        flag += [False]
    rest = 10

    cur = n
    while rest:
        tmp = cur
        while tmp:
            if not flag[tmp%10]:
                flag[tmp%10] = True
                rest -= 1
            tmp /= 10
        if rest:
            cur += n
    print cur
