#!/usr/bin/python

import os
import sys
import itertools
import collections
import decimal

decimal.getcontext().prec = 50

def solve(f, skip=False):
    b, m = f.read_int_list()
    if skip: return 0

    if 2**(b-2) < m: return "IMPOSSIBLE"

    res = 2**(b-2) - m
    div = []
    for i in xrange(2,b):
        if res == 0: break
        if res >= 2**(b-i-1):
            div.append(i-1)
            res -= 2**(b-i-1)

    if res != 0: raise

    ans = [[0] * b for _ in xrange(b)]

    for j in xrange(1,b):
        if j not in div:
            ans[0][j] = 1

    for i in xrange(1,b):
        for j in xrange(i+1,b):
            ans[i][j] = 1

    return "POSSIBLE\n" + "\n".join(["".join(map(str, l)) for l in ans])

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
    def read_decimal(self):
        self.linenum += 1
        return decimal.Decimal(self.f.readline().strip())
    def read_str(self):
        self.linenum += 1
        return self.f.readline().strip()

    def read_int_list(self):
        self.linenum += 1
        return map(int, self.f.readline().split())
    def read_float_list(self):
        self.linenum += 1
        return map(float, self.f.readline().split())
    def read_decimal_list(self):
        self.linenum += 1
        return map(decimal.Decimal, self.f.readline().split())
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
