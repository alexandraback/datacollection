#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import sys

def ReadIn():
    cases = int(raw_input())
    for case in xrange(1, cases + 1):
        e, r, n = [int(x) for x in raw_input().split()]
        v = [int(x) for x in raw_input().split()]
        yield case, e, r, n, v

def Solve(energy, regain, n, v):
    now = energy
    ret = 0
    for i in xrange(n):
        j = i + 1
        while j < n and v[j] < v[i]: j += 1
        if j == n:
            ret += now * v[i]
            now = regain
        else:
            need = energy - (j - i) * regain
            if need < 0: need = 0
            if need > now: need = now
            ret += (now - need) * v[i]
            now = need + regain
        if now > energy: now = energy
    return ret

if __name__ == '__main__':
    for case, energy, regain, n, v in ReadIn():
        print 'Case #%d: %d' % (case, Solve(energy, regain, n, v))
