#!/usr/bin/python

import os
import sys
import itertools
import collections
import decimal

decimal.getcontext().prec = 50

def solve(f, skip=False):
    c = collections.Counter(f.read_str())
    if skip: return 0

    ans = [0] * 10

    ans[0] = c['Z']
    for i in "ZERO":
        c[i] -= ans[0]
    ans[2] = c['W']
    for i in "TWO":
        c[i] -= ans[2]
    ans[4] = c['U']
    for i in "FOUR":
        c[i] -= ans[4]
    ans[6] = c['X']
    for i in "SIX":
        c[i] -= ans[6]
    ans[8] = c['G']
    for i in "EIGHT":
        c[i] -= ans[8]
    ans[1] = c['O']
    for i in "ONE":
        c[i] -= ans[1]
    ans[5] = c['F']
    for i in "FIVE":
        c[i] -= ans[5]
    ans[3] = c['T']
    for i in "THREE":
        c[i] -= ans[3]
    ans[7] = c['V']
    for i in "SEVEN":
        c[i] -= ans[7]
    ans[9] = c['I']

    return "".join([str(i)*ans[i] for i in xrange(len(ans))])

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
