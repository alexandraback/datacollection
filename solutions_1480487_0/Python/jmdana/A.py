#!/usr/bin/env python

#
# Copyright (c) 2012 J.M. Dana
#

import fileinput
import string
import sys
import os
import re

def doit(x):
    X=sum(x)
    n=len(x)
    mini=[]
    
    for idx,person in enumerate(x):
        total=0.0
        
        for person2 in x[:idx]+x[idx+1:]:
            total+=(((person-person2)/X)+1)/n
                        
        mini.append(abs(1-total))
            
    return string.join(['%.6f' % (i*100) for i in mini],' ')

theIN=fileinput.FileInput()

N = int(theIN.readline())

for case in range(1,N+1):
    #line=theIN.readline().strip('\n')
    line=map(float,theIN.readline().strip('\n').split(' '))
    #print line
    print 'Case #%d: %s' % (case,doit(line[1:]))

