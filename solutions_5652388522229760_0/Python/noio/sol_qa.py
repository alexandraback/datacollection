#! /usr/bin/python

__author__ = 'BJG Association'

### IMPORTS ###
import sys
import numpy as np
import scipy.ndimage as ndi
from pprint import pprint


### FUNCTIONS ###
def solve(N):
    if N == 0:
        return "INSOMNIA"
    
    seen = set()

    i = 1

    while len(seen) < 10:
        n = i * N
        for digit in str(n):
            seen.add(digit)
        i += 1

    return n


### PROCESS INPUT FILE ###

if __name__ == '__main__':
    f = open(sys.argv[1])
    fout = open(sys.argv[1].replace('.in','.out'),'w')

    T = int(f.readline())

    for case in xrange(T):
        N = int(f.readline())
        

        ans = solve(N)
        print ans
        fout.write('Case #%d: %s\n'%(case+1,ans))
