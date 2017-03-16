#! /usr/bin/env python
from __future__ import division
import sys
import itertools


def main():
    t = int(raw_input())
    for i in xrange(1, t + 1):
        ss = map(int, raw_input().split())[1:]
        print 'Case #%d:' % i
        print '\n'.join(' '.join(map(str, ln)) for ln in solve(ss))


def solve(ss):
    mem = {}
    for n in xrange(1, len(ss)):
        for c in itertools.combinations(ss, n):
            v = sum(c)
            if v in mem:
                return mem[v], c
            mem[v] = c
    return ('Impossible',)


if __name__ == '__main__':
    sys.exit(main())
