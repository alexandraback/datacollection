#!/usr/bin/env python

import sys
from math import ceil, floor, sqrt

# This list was generated from my other program: fas-gen.py
fas_roots = [
        1,
        2,
        3,
        11,
        22,
        101,
        111,
        121,
        202,
        212,
        1001,
        1111,
        2002,
        10001,
        10101,
        10201,
        11011,
        11111,
        11211,
        20002,
        20102,
        100001,
        101101,
        110011,
        111111,
        200002,
        1000001,
        1001001,
        1002001,
        1010101,
        1011101,
        1012101,
        1100011,
        1101011,
        1102011,
        1110111,
        1111111,
        2000002,
        2001002]

def read_ints():
    return [int(x) for x in sys.stdin.readline().split()]

T = int(input())

for case in range(T):
    print("Case #", case+1, ": ", sep='', end='')

    A, B = read_ints()

    start = ceil(sqrt(A))
    end = floor(sqrt(B))

    count = 0
    root_start = -1
    root_end = len(fas_roots)-1
    for num in range(len(fas_roots)):
        if start <= fas_roots[num]:
            if end  >= fas_roots[num]:
                root_start = num
            break
    if root_start >= 0:
        for num in range(root_start, len(fas_roots)):
            if end < fas_roots[num]:
                root_end = num-1
                break

        print(root_end - root_start + 1)
    else:
        print('0')

