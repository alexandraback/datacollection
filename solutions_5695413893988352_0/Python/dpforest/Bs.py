#!/usr/bin/python

import os
import sys
import itertools
import collections
import decimal

decimal.getcontext().prec = 50

def solve(f, skip=False):
    c, j = f.read_str_list()
    if skip: return 0

    cl = []
    jl = []
    n = len(c)

    for item in itertools.product("0123456789", repeat=n):
        for i, v in enumerate(item):
            if c[i] != '?' and c[i] != item[i]: break
        else:
            cl.append(int("".join(item)))
        for i, v in enumerate(item):
            if j[i] != '?' and j[i] != item[i]: break
        else:
            jl.append(int("".join(item)))

    ans = (float('inf'), 0, 0)

    for ci in cl:
        for ji in jl:
            if abs(ji-ci) < ans[0]:
                ans = (abs(ji-ci), ci, ji)
            elif abs(ji-ci) == ans[0]:
                if ci < ans[1]:
                    ans = (abs(ji-ci), ci, ji)
                elif ci == ans[1]:
                    if ji < ans[2]:
                        ans = (abs(ji-ci), ci, ji)

    return "%s %s"%(str(ans[1]).zfill(n), str(ans[2]).zfill(n))

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
