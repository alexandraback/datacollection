#!/usr/bin/python3

import sys

t = int(sys.stdin.readline())

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

imenovalci = [2**x for x in range(40+1)]

def solve(p, q):
    ret = 41
    gen = 0
    while q < 2**40:
        p *= 2
        q *= 2
    while imenovalci[gen] <= p:
        gen += 1
        ret -= 1
    return ret

for i in range(1, t+1):
    p, q = map(int, sys.stdin.readline().split('/'))
    d = gcd(p, q)
    p //= d
    q //= d
    if q not in imenovalci:
        print('Case #%d: impossible' % i)
        continue
    sol = solve(p, q)
    print('Case #%d: %d' % (i, sol))
