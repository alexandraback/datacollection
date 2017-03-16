#!/usr/env/python

from bisect import bisect_left
from sys import stdin
from fractions import gcd

POWS = {}
POWS_l = []

def init_pows(max):
    for i in range(max):
        p = pow(2, i)
        POWS[p] = i
        POWS_l.append(p)


def solve_prob():
    raw = stdin.readline().strip()
    (a, b) = [int(i) for i in raw.split('/')]
    g = gcd(a, b)    
    if g != 1:
        b = b / g
        a = a / g
    try:
        all = POWS[b]
    except KeyError:
        return 'impossible'
    pos = bisect_left(POWS_l, a)
    if pos != 0:
        pos -= 1
    return str(all - pos)

init_pows(41)

nb = int(stdin.readline().strip())
for i in range(1, nb + 1):
    print('Case #{}: {}'.format(i, solve_prob()))
