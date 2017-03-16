#!/usr/bin/python

from copy import deepcopy
from collections import deque

def ir():
    return int(raw_input())

def ia():
    line = raw_input()
    line = line.split()
    return map(int, line)

def sa():
    line = raw_input()
    line = line.split()
    return line

def s2l(s):
    ans = []
    for e in s:
        if e=='?':
            f = True
            v  = 0
        else:
            f = False
            v = int(e)
        ans.append( (f, v) )
    return ans

def l2s(l):
    ans = ''
    for f, v in l:
        ans = ans + str(v)
    return ans

def l2n(l):
    ans = 0
    p   = 1
    for f, v in reversed(l):
        ans = ans + p*v
        p   = p*10
    return ans


def GLG(l):
    while True:
        for i, (f, v) in enumerate(l):
            if not f: continue
            elif v==9: l[i] = f, 0
            else     :
                l[i] = f, v+1
                break
        else:
            yield l
            return
        yield l

def better(l1, l2,    l1m, l2m):
    n1 = l2n(l1)
    n2 = l2n(l2)

    n1m = l2n(l1m)
    n2m = l2n(l2m)

    d   = abs(n1 - n2)
    dm  = abs(n1m - n2m)

    if d<dm:
        return deepcopy(l1), deepcopy(l2)
    if d==dm and n1<n1m:
        return deepcopy(l1), deepcopy(l2)
    if d==dm and n1==n1m and n2<n2m:
        return deepcopy(l1), deepcopy(l2)
    return deepcopy(l1m), deepcopy(l2m)

def solve(s1, s2):
    l10 = s2l(s1)
    l20 = s2l(s2)

    l1m = deepcopy(l10)
    l2m = deepcopy(l20)

    for l1 in GLG(l10):
        for l2 in GLG(l20):
            l1m, l2m = better(l1, l2, l1m, l2m)
    return l2s(l1m), l2s(l2m)

def copy(s):
    ans = ''
    for e in s:
        if e=='?': ans = ans + '0'
        else     : ans = ans + str(e)
    return ans

T = ir()
for i in range(T):
    s1, s2 = sa()
    if   s1 == '???':
        b1, b2 = copy(s2), copy(s2)
    elif s2 == '???':
        b1, b2 = copy(s1), copy(s1)
    else:
        b1, b2 = solve(s1, s2)
    print 'Case #%d: %s %s' % (i+1, b1, b2)
