#!/usr/bin/python

import os
import sys
import itertools
from fractions import gcd
import numpy as np

def cmp(s1, s2, s3, s4):
    if 'O' == s1 == s2 == s3 == s4:
        return 'O'
    elif 'X' == s1 == s2 == s3 == s4:
        return 'X'
    else:
        return False

def test(b):
    d1 = cmp(b[0,0],b[1,1],b[2,2],b[3,3])
    if d1: return d1
    d2 = cmp(b[0,3],b[1,2],b[2,1],b[3,0])
    if d2: return d2

    for i in xrange(3):
        h = cmp(*list(b[:,i]))
        if h: return h

    for i in xrange(3):
        h = cmp(*list(b[i,:]))
        if h: return h

    return False

def solve(f):
    board = np.array([list(f.read_str()) for i in xrange(4)])
    tpoint = (board == 'T')
    bl = []

    if tpoint.any():
        for s in ['O', 'X']:
            b = board.copy()
            b[tpoint] = s
            bl.append(b)
    else:
        bl.append(board)

    for board in bl:
        res = test(board)
        if res: return '%s won'%res

    if (board=='.').any():
        return 'Game has not completed'
    else:
        return 'Draw'


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
        if cnum == case+1: print 'line: %d'%f.linenum
        line = 'Case #%d: %s\n'%(case+1,str(solve(f)))
        g.write(line)
        if not cnum or cnum == case+1: print line,
        f.read_str()
