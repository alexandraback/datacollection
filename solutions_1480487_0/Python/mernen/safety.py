#! /usr/bin/env python
from __future__ import division
import sys


def main():
    t = int(raw_input())
    for i in xrange(1, t + 1):
        ss = map(int, raw_input().split())[1:]
        print 'Case #%d:' % i,
        print ' '.join(str(m) for m in solve(ss))


def solve(ss):
    x = sum(ss)
    if len(ss) == 2:
        goal = x
    else:
        goal = x * 2 / len(ss)  # ??
    a = []
    for s in ss:
        m = (goal - s) / x
        a.append(max(m, 0) * 100)
    return a

if __name__ == '__main__':
    sys.exit(main())
