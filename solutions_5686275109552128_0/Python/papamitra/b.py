#!/usr/bin/env python3

import sys
import math
import bisect

def solve1(t, ps):
    if ps[0] <= 3:
        return ps[0]+t

    fst = ps[0]
    x = math.ceil(fst/2)
    x2 = math.floor(fst/2)

    ary = []
    for i in range(x2):
        if x2-i<2: continue
        ps2 = ps[1:]
        ps2.reverse()
        bisect.insort(ps2,x+i)
        bisect.insort(ps2,x2-i)
        ps2.reverse()
        ary.append(ps2)

    if ary == []:
        return fst+t

    return min(fst+t, *[solve1(t+1,p) for p in ary])

def solve(l):
    ps = [int(x) for x in l[:-1].split(' ')]
    ps.sort(reverse=True)
    return solve1(0, ps)

def main():
    t = int(sys.stdin.readline())
    for i in range(t):
        sys.stdin.readline()
        s = solve(sys.stdin.readline())
        print("Case #{0}: {1}".format(i+1, s))

if __name__ == '__main__':
    main()
