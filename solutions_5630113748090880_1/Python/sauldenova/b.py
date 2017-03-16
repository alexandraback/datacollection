#!/usr/local/bin/python3

from __future__ import print_function

T = int(input())
for t in range(1, T + 1):
    print("Case #", t, ":", sep= '', end='')
    N = int(input())
    num_count = [0 for i in range(2510)]
    for i in range(2 * N - 1):
        for val in [int(s) for s in str(input()).split(' ')]:
            num_count[val] += 1

    result = []
    for i in range(2510):
        if num_count[i] % 2 == 1:
            result.append(i)

    result = sorted(result)

    for i in result:
        print(' ', i, sep='', end='')

    print()

