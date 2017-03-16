#!/usr/bin/python

import os
import sys
import itertools
import collections
import copy

def solve(f, skip=False):
    n = f.read_int()
    friends = [0] + f.read_int_list()
    if skip: return 0

    for size in xrange(n, 0, -1):
        for item in itertools.permutations(xrange(1,n+1), size):
            for i in xrange(size):
                if friends[item[i]] != item[i-1] and friends[item[i]] != item[(i+1)%size]:
                    break
            else:
                return size

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
        return map(int, self.f.readline().split())
    def read_float_list(self):
        self.linenum += 1
        return map(float, self.f.readline().split())
    def read_long_list(self):
        self.linenum += 1
        return map(long, self.f.readline().split())
    def read_str_list(self):
        self.linenum += 1
        return self.f.readline().split()

if __name__ == '__main__':
    filename = sys.argv[1] if len(sys.argv) > 1 else sys.argv[0].replace('.py', '-sample.in')
    cnum = int(sys.argv[2]) if len(sys.argv) > 2 else None
    output = filename[:-3]+'.out' if filename[-3:] == '.in' else filename+'.out'
    f = Reader(filename)
    cases = f.read_int()

    if cnum:
        for case in xrange(cases):
            if cnum == case+1:
                print '(line: %d) '%f.linenum
                line = 'Case #%d: %s\n'%(case+1,str(solve(f)))
                print line,
            else:
                solve(f, skip=True)
    else:
        g = open(output, 'w')
        for case in xrange(cases):
            line = 'Case #%d: %s\n'%(case+1,str(solve(f)))
            g.write(line)
            print line,
