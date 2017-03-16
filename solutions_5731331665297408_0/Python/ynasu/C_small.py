#!/usr/bin/env python

from itertools import permutations

def solve(N, codes, flights):
    connected = [[False] * N for i in xrange(N)]
    for flight in flights:
        connected[flight[0] - 1][flight[1] - 1] = True
        connected[flight[1] - 1][flight[0] - 1] = True
    res = 'a'
    for order in permutations(xrange(N)):
        stack = []
        first = True
        for city in order:
            if first:
                first = False
            else:
                while stack and not connected[stack[-1]][city]:
                    stack.pop()
                if not stack:
                    break
            stack.append(city)
        else:
            res = min(res, ''.join(codes[city] for city in order))
    return res

T = int(raw_input())
for x in xrange(1, T + 1):
    N, M = [int(v) for v in raw_input().split()]
    codes = [raw_input() for i in xrange(N)]
    flights = [[int(v) for v in raw_input().split()] for i in xrange(M)]
    print 'Case #%d: %s' % (x, solve(N, codes, flights))
