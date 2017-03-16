#!/usr/bin/python3

import sys
from itertools import *

def solve(ss):
    cur = 0
    inv = 0
    for i in range(len(ss)):
        s = int(ss[i])
        assert 0 <= s <= 9
        if s == 0:
            continue
        if cur < i:
            inv += i - cur
            cur = i
        cur += s
    return inv


def parse(ist):
    n, ss = ist.readline().split()
    n = int(n)
    assert n >= 0 and n+1 == len(ss)
    assert ss.isdigit()
    return ss

def main():
    #err(DIGITS)
    T = int(sys.stdin.readline())
    for i in range(T):
        #err('Case {}'.format(i))
        res = solve(parse(sys.stdin))
        print('Case #{}: {}'.format(i+1, res))

def err(*m):
    print(*m, file=sys.stderr)

if __name__ == '__main__':
    sys.exit(main())
