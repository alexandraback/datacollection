#! /usr/bin/env python3

from collections import Counter

digit = [
    'ZERO',
    'ONE',
    'TWO',
    'THREE',
    'FOUR',
    'FIVE',
    'SIX',
    'SEVEN',
    'EIGHT',
    'NINE',
]

specials = [
    ('Z', 0),
    ('W', 2),
    ('U', 4),
    ('X', 6),
    ('G', 8),
    ('O', 1),
    ('T', 3),
    ('F', 5),
    ('S', 7),
    ('I', 9),
]


def solve():
    s = input()
    cnts = Counter()
    ans = []
    for c in s:
        cnts[c] += 1
    
    for c, d in specials:
        cnt = cnts[c]
        ans.append(str(d) * cnt)
        for ch in digit[d]:
            cnts[ch] -= cnt

    return ''.join(sorted(ans))

# codejam style

T = int(input())

for TT in range(1, T+1):
    ans = solve()
    print('Case #{}: {}'.format(TT, ans))
