#!/usr/bin/env python3

from string import ascii_uppercase
from heapq import nlargest


def solve(b, m):
    if m > 2**(b-2):
        return 'IMPOSSIBLE'
    matrix = [[0]*(b-1)+[1]]
    for source in range(1, b):
        row = []
        for dest in range(b):
            if dest <= source:
                row.append(0)
            else:
                row.append(1)
        matrix.append(row)
    m -= 1
    pos = b-1
    while m > 0:
        pos -= 1
        if m % 2 == 1:
            matrix[0][pos] = 1
        m //= 2
    rows = [''.join(str(i) for i in r) for r in matrix]
    return "POSSIBLE\n%s" % '\n'.join(rows)


def main():
    for i in range(int(input())):
        b, m = [int(s) for s in input().split()]
        print("Case #%s: %s" % (i+1, solve(b, m)))
main()