#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys,string

def helper(A, arr, l):
    if l == 0:
        return 0
    x, rest = arr[0], arr[1:]
    if A > x:
        return helper(A + x, rest, l - 1)
    if A == 1:
        return l
    return min(l, 1 + helper(A + (A-1), arr, l))

def run(A, arr):
    return helper(A, arr, len(arr))
    
if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) > 1:
        fname = sys.argv[1]
        if fname != "-":
            f = open(fname)
    N = int(f.readline())
    for _num in xrange(N):
        A, N = map(int, f.readline().split())
        arr = map(int, f.readline().split())
        ret = run(A, sorted(arr))
        print "Case #%d: %s" % (_num+1, ret)
