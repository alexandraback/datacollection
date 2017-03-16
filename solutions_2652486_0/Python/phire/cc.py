#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os
from pprint import pprint
from collections import defaultdict
from random import randint, choice

dd = defaultdict(list)
def gen():
    d = [1, 2, 3, 4, 5]
    for i in xrange(len(d)):
        for j in xrange(i, len(d)):
            for k in xrange(j, len(d)):
                dd[d[i] * d[j] * d[k]].append((d[i], d[j], d[k]))

def solve(p):
    have = set()
    for k in p:
        if len(dd[k]) > 1:
            continue
        elif len(dd[k]) == 1:
            for i in dd[k][0]:
                if i > 1:
                    have.add(i)
        else:
            assert False
    out = 0
    for c in have:
        sys.stdout.write(str(c))
        out += 1
    hlist = list(have)
    if not hlist:
        hlist = [2, 3, 4, 5]
    while out < 3:
        sys.stdout.write(str(choice(hlist)))
        out += 1
    print

#def main():
#    gen()
#    pprint(dd.items())

def main():
    sys.stdin.readline()
    gen()
    R, N, M, K = map(int, sys.stdin.readline().strip().split())
    print "Case #1:"
    for i in xrange(R):
        prods = map(int, sys.stdin.readline().strip().split())
        solve(prods)



if __name__ == '__main__':
    main()
