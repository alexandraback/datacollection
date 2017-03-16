#! /usr/bin/env pypy

import sys

MAXITER = int(1e10)

n = int(sys.stdin.readline().strip())

def solve(x):
    inf = "INSOMNIA"
    if x in [0]:
        return inf
    d = dict( (str(x), 0) for x in range(10) )
    N = 0
    while 1:
        N += 1
        if N >= MAXITER:
            return inf
        num = N * x
        for digit in str(num):
            if not d[digit]:
                d[digit] = 1
        if 0 not in d.values():
            return num

for i in range(n):
    line = sys.stdin.readline().strip()
    a = int(line)
    r = solve(a)
    print("Case #{}: {}".format(i+1, r))

