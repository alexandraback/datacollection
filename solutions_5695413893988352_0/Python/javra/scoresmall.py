#!/usr/bin/python3
from math import *
from sys import stderr
from itertools import *
def out(s):
    print(s, end='')
def err(*s):
    print(*s, file=stderr)

def solve():
    C,J = input().strip().split()    

    L = len(C)

    possibleC = []
    possibleJ = []
    best = (1000, 2000)

    l = 10**len(C)

    for c in range(l):
        cs = str(c).zfill(L)
        good = True
        for i in range(L):
            if C[i] != "?" and cs[i] != C[i]:
                good = False
        if good:
            possibleC.append(c)

    for j in range(l):
        js = str(j).zfill(L)
        good = True
        for i in range(L):
            if J[i] != "?" and js[i] != J[i]:
                good = False
        if good:
            possibleJ.append(j)

    for c in possibleC:
        for j in possibleJ:
            if abs(j - c) < abs(best[1] - best[0]):
                best = (c,j)
            if abs(j - c) == abs(best[1] - best[0]):
                if c < best[0] or (c == best[0] and j < best[1]):
                    best = (c,j)

    out(str(best[0]).zfill(L))
    out(" ")
    out(str(best[1]).zfill(L))

T = int(input())
for t in range(1, T+1):
    out("Case #%d: " % (t))
    solve()
    print()
