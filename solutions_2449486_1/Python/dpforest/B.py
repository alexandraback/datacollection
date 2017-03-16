#!/usr/bin/python

import os
import sys
import itertools
import copy
from fractions import gcd
import numpy as np


def solve(f):
    n,m = f.read_int_list()

    lawn = np.array([f.read_int_list() for i in xrange(n)])
    l = np.ones(lawn.shape)*100

    while (lawn != l).any():
        flg = False
        for x in xrange(n):
            h = lawn[x,:].max()
            if (l[x,:]-h).sum() > 0:
                flg = True
                l[x,:] = h
        for y in xrange(m):
            h = lawn[:,y].max()
            if (l[:,y]-h).sum() > 0:
                flg = True
                l[:,y] = h
#        print l
        if not flg: return 'NO'

    return 'YES'

class Reader(object):
    def __init__(self, filename):
        self.f = open(filename)
        self.linenum = 1

    def read_int(self):
        self.linenum += 1
        return int(self.f.readline().strip())
    def read_float(self):
        self.linenum += 1
        return float(self.f.readline().strip())
    def read_long(self):
        self.linenum += 1
        return long(self.f.readline().strip())
    def read_str(self):
        self.linenum += 1
        return self.f.readline().strip()

    def read_int_list(self):
        self.linenum += 1
        return [int(item) for item in self.f.readline().split()]
    def read_float_list(self):
        self.linenum += 1
        return [float(item) for item in self.f.readline().split()]
    def read_long_list(self):
        self.linenum += 1
        return [long(item) for item in self.f.readline().split()]
    def read_str_list(self):
        self.linenum += 1
        return self.f.readline().split()

if __name__ == '__main__':
    filename = sys.argv[1]
    cnum = int(sys.argv[2]) if len(sys.argv) > 2 else None
    output = filename[:-3]+'.out' if filename[-3:] == '.in' else filename+'.out'
    f = Reader(filename)
    g = open(output, 'w')
    cases = f.read_int()
    for case in xrange(cases):
#        if cnum == case+1: print 'line: %d'%f.linenum
        print '(%d) '%f.linenum
        line = 'Case #%d: %s\n'%(case+1,str(solve(f)))
        g.write(line)
        if not cnum or cnum == case+1: print line,
