#!/usr/bin/python3

import sys
from collections import Counter

numbers = {
        0: 'ZERO',
        1: 'ONE',
        2: 'TWO',
        3: 'THREE',
        4: 'FOUR',
        5: 'FIVE',
        6: 'SIX',
        7: 'SEVEN',
        8: 'EIGHT',
        9: 'NINE'
        }

def solve(S):
    a = [0 for x in range(10)]
    c = Counter()
    for x in S:
        c[x] += 1

    a[0] = c['Z']
    a[2] = c['W']
    a[4] = c['U']
    a[6] = c['X']
    a[7] = c['S'] - a[6]
    a[5] = c['V'] - a[7]
    a[8] = c['G']
    a[9] = c['I'] - a[5] - a[6] - a[8]
    a[3] = c['H'] - a[8]
    a[1] = c['O'] - a[0] - a[2] - a[4]

    digs = []
    for d in range(10):
        digs.extend([str(d) for _ in range(a[d])])

    return ''.join(digs)

T = int(sys.stdin.readline().strip())

for t in range(T):
    S = sys.stdin.readline().strip()
    print("Case #{}: {}".format(t+1, solve(S)))

