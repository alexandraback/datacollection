#! /usr/bin/python

__author__ = 'BJG Association'

### IMPORTS ###
import sys
import numpy as np
import scipy.ndimage as ndi
from pprint import pprint


### FUNCTIONS ###
def solve(stack):
    
    flips = 0
    for i in range(1, len(stack)):
        deze = stack[i]
        vorige = stack[i - 1]

        if deze != vorige:
            flips += 1

    if stack[len(stack) - 1] == '-':
        flips += 1
    
    return flips


### PROCESS INPUT FILE ###

if __name__ == '__main__':
    f = open(sys.argv[1])
    fout = open(sys.argv[1].replace('.in','.out'),'w')

    T = int(f.readline())

    for case in xrange(T):
        stack =  f.readline().strip()
        

        ans = solve(stack)
        print "case %s: %s ans: %s" % (T, stack, ans)
        fout.write('Case #%d: %s\n'%(case+1,ans))
