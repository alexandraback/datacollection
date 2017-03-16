#!/usr/bin/python

def scoreFor(a, b, c):
    return max(0, a) + max(0, b) + max(0, c)

def solve(N, S, p, *scores):
    count = 0
    for score in scores:
        if scoreFor(p - 1, p - 1, p) <= score:
            count += 1
        elif S > 0 and scoreFor(p - 2, p - 2, p) <= score:
            count += 1
            S -= 1
    return count

T = int(raw_input())
for i in range(T):
    print "Case #%i: %i" % (i+1, solve(*map(int, raw_input().split(' '))))

