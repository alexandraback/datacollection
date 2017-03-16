#!/usr/bin/python3

import sys
from itertools import *
#from functools import *
from pprint import pprint


def solve(X, R, C):
    if ((R*C)%X) != 0:
        perr(0)
        return
    if X > R and X > C:
        perr(1)
        return
    if X >= 7:
        perr(2)
        return
    if X//2 > min(R, C):
        perr(3)
        return
    return True

def parse(ist):
    xrc = [int(i) for i in ist.readline().split()]
    assert len(xrc) == 3
    assert all(i > 0 for i in xrc)
    return xrc

def main():
    T = int(sys.stdin.readline())
    for i in range(T):
        #err('Case {}'.format(i))
        res = solve(*parse(sys.stdin))
        res = 'GABRIEL' if res else 'RICHARD'
        print('Case #{}: {}'.format(i+1, res))

def err(*m):
    print(*m, file=sys.stderr)

def perr(*m):
    pprint(m, stream=sys.stderr)

if __name__ == '__main__':
    sys.exit(main())
