#!/usr/local/bin/python2.7
# encoding: utf-8
'''
Created on 12 May 2013

@author: Artem
'''
from __future__ import division
from math import sqrt
import os
import sys
import time
import math


def write_case(f_out, out, k):
    out = "Case #%d: %s\n" % (k, out)
    f_out.write(out)
    print out

def solve(f_in, f_out):
    T = f_in.readline()
    if not T:
        print 'The input file is empty!'
        sys.exit()
    T = int(T)
    
    for k in xrange(1, T+1):
        L, n = f_in.readline().split()
        n = int(n)
        #print L, n
        vow = ['a', 'e', 'i', 'o', 'u']
        
        #numb = int(round((len(L)-n+1)**2/float(2))) + len(L)//2 - 1
        
        m = [[]]*10
        lis =[L[i:i+n] for i in xrange(len(L)-n+1)]
        nn = 0
        for j in xrange(n-1, len(L)):
            lis =[L[i:i+j+1] for i in xrange(len(L)-j)]
            for ll in lis:
                lenn = 0
                for l in ll:
                    if not l in vow:
                        lenn += 1
                    else:
                        lenn = 0
                    if lenn == n:
                        nn += 1
                        break
        out = nn
        write_case(f_out, out, k)

def main():
    START = time.time()
    my_dir = os.getcwd()
    name = os.path.basename(__file__)[:-3:]
    
    file_in = "%s\\input\\%s.in" % (my_dir, name)
    file_out = "%s\\output\\%s.out" % (my_dir, name)
    with open(file_in, 'a+') as f_in:
        with open(file_out, 'w') as f_out:
            solve(f_in, f_out)
    
    print 'All done in %f s' % (time.time()-START)
    
if __name__ == '__main__':
    main()