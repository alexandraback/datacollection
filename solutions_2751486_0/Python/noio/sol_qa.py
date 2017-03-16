#! /usr/bin/python

__author__ = 'Thomas "noio" van den Berg'

### IMPORTS ###
import sys
import numpy as np
import scipy.ndimage as ndi
from pprint import pprint

VOW = list("aeiou")
CONS = list("bcdfghjklmnpqrstvwxyz")

### FUNCTIONS ###

def do(name, n):
    val = 0
    i = 0
    last = None
    print 'n =', n
    iscon = np.array([letter in CONS for letter in name])
    strel = np.ones(n+(n-1))
    strel[n:] = 0
    endpos = ndi.morphology.binary_erosion(iscon, structure=strel)
    print name
    print "".join("x" if l else "_" for l in endpos)
    while i < len(name):
        if endpos[i]:
            last = i
        if last is not None:
            towhere = min(last-n, i-n)
            val += towhere + 2
            # print '_' * (towhere + 1) + '=' * (i - towhere) + ' (%d)' % (towhere+2)
        i += 1
    return val


### PROCESS INPUT FILE ###

if __name__ == '__main__':
    f = open(sys.argv[1])
    fout = open(sys.argv[1].replace('.in','.out'),'w')

    T = int(f.readline())
    for case in xrange(T):
        name, n = f.readline().strip().split(' ')
        n = int(n)
        
        ans = do(name, n)
        print ans
        fout.write('Case #%d: %s\n'%(case+1,ans))
