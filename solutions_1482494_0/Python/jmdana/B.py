#!/usr/bin/env python

#
# Copyright (c) 2012 J.M. Dana
#

import fileinput
import string
import sys
import os
import re

def sortit(a,b):
    return a[1] - b[1]

def doit(levels):
    nStars=0
    steps=0
    
    levels.sort(cmp=sortit,reverse=True)
    
    while 1:
        can=False
        
        while min([i[1] for i in levels]) <= nStars:
            idx=min([(i[1],idx) for idx,i in enumerate(levels)])[1]
            if levels[idx][0] == 'X':
                nStars+=1
            else:
                nStars+=2
            
            steps+=1
            levels[idx]=['X','X']
            can=True
                            
        
        if [i[1] for i in levels] == ['X'] * len(levels):
            break
            
        if min([i[0] for i in levels]) <= nStars:
            for idx,l in enumerate(levels):
                if l[0] <= nStars:
                    nStars+=1
                    steps+=1
                    levels[idx][0]='X'
                    can=True
                    break
        
        if not can:
            break
    
    return steps if [i[1] for i in levels] == ['X'] * len(levels) else 'Too Bad'

theIN=fileinput.FileInput()

N = int(theIN.readline())

for case in range(1,N+1):
    nlevels=map(int,theIN.readline().strip('\n').split(' '))[0]
    levels=[]
    
    for l in range(nlevels):
        levels.append(map(int,theIN.readline().strip('\n').split(' ')))

    print 'Case #%d: %s' % (case,doit(levels))

