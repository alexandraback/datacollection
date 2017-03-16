#!/usr/bin/python3

import sys
from collections import Counter

def get_diff(s, w):
    C = s[0:w]
    J = s[w:]
    return abs(int(C) - int(J))

def subs(mask, num, b):
    num = str(num)
    num = num.zfill(b)
    z = 0
    s = []
    for c in mask:
        if c == '?':
            s.append(num[z])
            z += 1
        else:
            s.append(c)
    return ''.join(s)

def solve(C, J):
    assert(len(C) == len(J))
    w = len(C)
    mask = C + J
    b = len([x for x in mask if x == '?'])
    if b == 2*w:
        z = '0'*w
        return (z, z)

    best = None
    bestS = None

    for i in range(10**b):
        s = subs(mask, i, b)
        d = get_diff(s, w)
        #print(mask, s, d)
        if best == None or d < best:
            best = d
            bestS = s

    return (bestS[0:w], bestS[w:])


T = int(sys.stdin.readline().strip())

for t in range(T):
    C, J = sys.stdin.readline().strip().split()
    newC, newJ = solve(C, J)
    print("Case #{}: {} {}".format(t+1, newC, newJ))

