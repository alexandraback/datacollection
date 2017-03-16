#!/usr/bin/python

import os
import sys
import itertools
import collections
import decimal

decimal.getcontext().prec = 50

def solve(f, skip=False):
    j, p, s, k = f.read_int_list()
    if skip: return 0

    full = {(1,1,1)}
    jp = collections.defaultdict(int)
    ps = collections.defaultdict(int)
    sj = collections.defaultdict(int)
    jp[(1,1)] += 1
    ps[(1,1)] += 1
    sj[(1,1)] += 1

    for jj in xrange(1,j+1):
        for pp in xrange(1,p+1):
            for ss in xrange(1,s+1):
                if (jj, pp, ss) in full: continue
                if jp[(jj,pp)] >= k: continue
                if ps[(pp,ss)] >= k: continue
                if sj[(ss,jj)] >= k: continue
                full.add((jj,pp,ss))
                jp[(jj,pp)] += 1
                ps[(pp,ss)] += 1
                sj[(ss,jj)] += 1

    ans2 = []
    for a in full:
        ans2.append(" ".join(map(str, a)))

    return "%d\n%s"%(len(full), "\n".join(ans2))

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
