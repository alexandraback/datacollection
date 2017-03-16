#!/usr/bin/python3

import sys
from itertools import groupby

def solve(x, y):
    res = ''
    if x > 0:
        res += 'WE' * x
    else:
        res += 'EW' * -x
    if y > 0:
        res += 'SN' * y
    else:
        res += 'NS' * -y
    return res

def main():
    T = int(next(sys.stdin))
    for t in range(T):
        x, y = map(int, next(sys.stdin).split())
        print("Case #{}: {}".format(t+1, solve(x, y)))

main()

