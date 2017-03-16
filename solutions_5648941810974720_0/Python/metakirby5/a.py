#!/usr/bin/env python3
from collections import defaultdict

def main(*args):
    x = args[0]
    o = 'ZWURFXVTIN'
    a = {
        'Z': 0,
        'W': 2,
        'U': 4,
        'R': 3,
        'F': 5,
        'X': 6,
        'V': 7,
        'T': 8,
        'I': 9,
        'N': 1,
    }
    m = {
        0: 'ZERO',
        1: 'ONE',
        2: 'TWO',
        3: 'THREE',
        4: 'FOUR',
        5: 'FIVE',
        6: 'SIX',
        7: 'SEVEN',
        8: 'EIGHT',
        9: 'NINE',
    }
    r = [0] * 10
    d = defaultdict(int)
    for c in x:
        d[c] += 1
    for c in o:
        n = a[c]
        r[n] = d[c]
        for cc in m[n]:
            d[cc] -= r[n]
    return ''.join(str(k) * v for k, v in enumerate(r))

if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #{}: {}".format(i + 1, main(*input().split())))
