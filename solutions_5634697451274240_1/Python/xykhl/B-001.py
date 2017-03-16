#! /usr/bin/env pypy

import sys

n = int(sys.stdin.readline().strip())

def flip(a):
    r = []
    for x in reversed(a):
        if x == '+':
            r.append('-')
        elif x == '-':
            r.append('+')
        else:
            raise ValueError('invalid pancake state: {}'.format(x))
    return r

def solve(s):
    a = list(s)
    r = 0
    while 1:
        xother = flip(a[0:1])[0]
        try:
            marker = a.index(xother)
        except ValueError as err:
            # pancakes are "coherent"
            if a[0] == '+':
                return r
            marker = len(a)
        a = flip(a[:marker]) + a[marker:]
        r += 1

for i in range(n):
    line = sys.stdin.readline().strip()
    a = line.strip()
    r = solve(a)
    print("Case #{}: {}".format(i+1, r))

