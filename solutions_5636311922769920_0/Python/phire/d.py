#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def mk_indices(K, C, s, f):
    indices = range(s, f)
    while len(indices) < C:
        indices.append(s)
    r = 0
    for i in indices:
        r = r * K + i
    return r

def solve(K, C, S):
    need = (K + C - 1) / C
    if need > S:
        return None
    ret = []
    for j in xrange(0, K, C):
        ret.append(mk_indices(K, C, j, min(j+C, K)) + 1)

    return ret

def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        K, C, S = map(int, sys.stdin.readline().split())
        r = solve(K, C, S)
        print "Case #%s: %s" % (t, " ".join(map(str, r)) if r else "IMPOSSIBLE")

if __name__ == '__main__':
    main()
