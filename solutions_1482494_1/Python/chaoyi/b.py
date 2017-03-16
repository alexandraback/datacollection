#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from heapq import *


def run(N, a, b):
    a_done = [False for _ in xrange(N)]

    target = [(k,i) for i,k in enumerate(b)]
    heapify(target)

    stars = 0
    steps = 0
    while True:
        if not target:
            return steps
        if target[0][0] <= stars:
            _,i = heappop(target)
            steps += 1
            if a_done[i]:
                stars += 1
            else:
                a_done[i] = True
                stars += 2
            continue
        else:
            target2 = [(k,i) for i,k in enumerate(b) if a[i] <= stars and not a_done[i]]
            if not target2:
                return "Too Bad"
            k,i = max(target2)
            a_done[i] = True
            stars += 1
            steps += 1
            continue
            
if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) > 1:
        fname = sys.argv[1]
        if fname != "-":
            f = open(fname)
    N = int(f.readline())
    for _num in xrange(N):
        NN, = map(int, f.readline().split())
        a, b = [], []
        for _ in xrange(NN):
            x, y = map(int, f.readline().split())
            a.append(x)
            b.append(y)
        ret = run(NN, a, b)
        print "Case #%d: %s" % (_num+1, ret)
