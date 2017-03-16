#!/usr/bin/python

import os
import sys
import itertools
import copy
from fractions import gcd
import numpy as np

def list2num(l):
    return sum([2**i for i in l])

def process(keys, chests, ckey, cinside, opened, memo):
    if len(chests) == len(opened): return opened
    if not keys: return False
    num = list2num(opened)
    if num in memo: return memo[num]

    for i, chest in enumerate(chests):
        if chest is None: continue
        if keys[ckey[i]] > 0:
            k = keys[:]
            c = chests[:]
            k[ckey[i]] -= 1
            for item in cinside[i]:
                k[item] += 1
            o = opened + (i+1,)
            c[i] = None
            r = process(k, c, ckey, cinside, o, memo)
            if r:
                return r

    memo[num] = False
    return False



def solve(f):
    knum, nnum = f.read_int_list()

    k = f.read_int_list()
    chests = [True]*nnum
    ckey = [None]*nnum
    cinside = [None]*nnum
    memo = {}
    keys = [0]*201

    for item in k:
        keys[item] += 1

    for i in xrange(nnum):
        l = f.read_int_list()
        ckey[i] = l[0]
        cinside[i] = l[2:]

    res =  process(keys, chests, ckey, cinside, (), {})

    if res:
        return ' '.join([str(i) for i in res])
    else:
        return 'IMPOSSIBLE'


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
