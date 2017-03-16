#!/usr/bin/env python3

# Google Code Jam
# Qualification Round 2016
# Problem C. Coin Jam
# Solution in Python by Smithers

import sys

input()
n, j = (int(x) for x in input().split())
print('Case #1:')

x = 2 ** (n - 1) + 1
count = 0
while count < j:
    if x > 2 ** n:
        print('FAIL', file=sys.stderr)
        break
    strx = '{:b}'.format(x)
    divisors = []
    for b in range(2, 11):
        y = int(strx, b)
        for p in 2, 3, 5, 7, 11:
            if y % p == 0:
                divisors.append(p)
                break
        else:
            break
    else:
        count += 1
        print(strx, *divisors)
    x += 2
