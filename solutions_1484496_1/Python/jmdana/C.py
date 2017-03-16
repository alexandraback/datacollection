#!/usr/bin/env python

#
# Copyright (c) 2012 J.M. Dana
#

import fileinput
import string
import sys
import os
import re
import itertools


def doit(x):
    memory={}
    
    for i in range(1,len(x)+1):
        for comb in itertools.combinations(x,i):
            if str(sum(comb)) in memory:
                if comb != memory[str(sum(comb))]:
                    out=string.join(['%d' % i for i in comb]," ") + '\n'
                    out+= string.join(['%d' % i for i in memory[str(sum(comb))]]," ")
                    return out
            else:
                memory[str(sum(comb))]=comb
        
    
    return 

theIN=fileinput.FileInput()

N = int(theIN.readline())

for case in range(1,N+1):
    line=map(int,theIN.readline().strip('\n').split(' '))

    print 'Case #%d: ' % (case)
    print '%s' % (doit(line[1:]))
