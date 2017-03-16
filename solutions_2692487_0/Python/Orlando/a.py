#!/usr/bin/env python

def read_int():
    return int(raw_input())

def read_ints():
    return [int(s) for s in raw_input().split()]


def solve(a, sizes):
    if a == 1:
        return len(sizes)
    sizes.sort()
    l = len(sizes)
    wins = []
    ops = 0
    for i in xrange(l):
        if a > sizes[i]:
            a += sizes[i]
            continue
        wins.append(ops + l - i)
        while a <= sizes[i]:
            a += a - 1
            ops += 1
        a += sizes[i]
    wins.append(ops)
    return min(wins)


t = read_int()

for caseno in xrange(1, t+1):
    a, n = read_ints()
    sizes = read_ints()
    print "Case #%d: %d" % (caseno, solve(a, sizes))
