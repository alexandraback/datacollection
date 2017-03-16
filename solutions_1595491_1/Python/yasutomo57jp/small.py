#!/usr/bin/env python
# -*- coding:utf-8 -*-
import sys

lines=int(sys.stdin.readline().strip())

for i in range(lines):
    invals=map(int,sys.stdin.readline().strip().split(" "))

    n=invals.pop(0)
    s=invals.pop(0)
    p=invals.pop(0)

    okvals=[]
    novals=[]
    for x in invals:
        a=x/3
        b=x%3
        if b==0:
            val=[a,a,a]
        elif b==1:
            val=[a,a,a+1]
        else:
            val=[a,a+1,a+1]
        
        #print val,
    
        if any( j >= p for j in val):
            okvals.append(val)
            #print "x",
        else:
            novals.append(val)


        #print ""

    amazing=0
    for val in novals:
        if amazing >= s: break
        
        aaa=sum(val)
        if aaa<p:continue
        a=aaa/3
        b=aaa%3
        if b==1:continue
        if b==0 and a+1 >=p: amazing+=1
        if b==2 and a+2 >=p: amazing+=1

    #print len(okvals),amazing,len(okvals)+amazing
    print "Case #%d: %d" % (i+1, len(okvals)+amazing)
