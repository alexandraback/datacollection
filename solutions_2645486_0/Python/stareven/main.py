#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import sys

def ReadIn():
    cases = int(raw_input())
    for case in xrange(1, cases + 1):
        e, r, n = [int(x) for x in raw_input().split()]
        v = [int(x) for x in raw_input().split()]
        yield case, e, r, n, v

def DFS(idx, s, remain, energy, regain, n, v):
    if idx == n:
        global ans
        ans = max(s, ans)
        return
    else:
        for use in xrange(remain + 1):
            DFS(idx + 1, s + use * v[idx], min(energy, remain - use + regain), energy, regain, n, v)

def Solve(energy, regain, n, v):
    global ans
    ans = 0
    DFS(0, 0, energy, energy, regain, n, v)
    return ans



if __name__ == '__main__':
    for case, energy, regain, n, v in ReadIn():
        print 'Case #%d: %d' % (case, Solve(energy, regain, n, v))
