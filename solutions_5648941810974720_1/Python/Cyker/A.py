#!/usr/bin/python

import sys
from collections import Counter

def solve(S):
    d = {}

    counter = Counter()
    for c in S:
        counter[c] += 1

    d[0] = counter['Z']
    counter['Z'] -= d[0]
    counter['E'] -= d[0]
    counter['R'] -= d[0]
    counter['O'] -= d[0]

    d[2] = counter['W']
    counter['T'] -= d[2]
    counter['W'] -= d[2]
    counter['O'] -= d[2]

    d[6] = counter['X']
    counter['S'] -= d[6]
    counter['I'] -= d[6]
    counter['X'] -= d[6]

    d[8] = counter['G']
    counter['E'] -= d[8]
    counter['I'] -= d[8]
    counter['G'] -= d[8]
    counter['H'] -= d[8]
    counter['T'] -= d[8]

    d[3] = counter['H']
    counter['T'] -= d[3]
    counter['H'] -= d[3]
    counter['R'] -= d[3]
    counter['E'] -= d[3]
    counter['E'] -= d[3]

    d[4] = counter['R']
    counter['F'] -= d[4]
    counter['O'] -= d[4]
    counter['U'] -= d[4]
    counter['R'] -= d[4]

    d[5] = counter['F']
    counter['F'] -= d[5]
    counter['I'] -= d[5]
    counter['V'] -= d[5]
    counter['E'] -= d[5]

    d[1] = counter['O']
    counter['O'] -= d[1]
    counter['N'] -= d[1]
    counter['E'] -= d[1]

    d[7] = counter['V']
    counter['S'] -= d[7]
    counter['E'] -= d[7]
    counter['V'] -= d[7]
    counter['E'] -= d[7]
    counter['N'] -= d[7]

    d[9] = counter['I']
    counter['N'] -= d[9]
    counter['I'] -= d[9]
    counter['N'] -= d[9]
    counter['E'] -= d[9]

    ans = []
    for k, v in d.items():
        if v > 0:
            for i in range(v):
                ans.append(str(k))
    ans.sort()
    return ''.join(ans)

T = int(input())
for t in range(T):
    S = input()
    ans = solve(S)
    print('Case #{}: {}'.format(t + 1,  ans))

