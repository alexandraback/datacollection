#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)

def solve1(N, M, K):
    # Incorrect, but solves small input!
    result = K
    if N == 1:
        result = K
    else:
        for l in range(0, M-1):
            h1_min = max(0, K // (l+2) - 2)
            for h1 in range(h1_min, N-1):
                upper_limit = (l+2) * (h1+2)
                if upper_limit < K:
                    continue
                for h2 in range(0, h1+1):
                    stones = l*2 + h1 + h2
                    diff = h1 - h2
                    if diff >= l:
                        continue
                    rect = l * h1
                    triangle = diff*(diff+1)//2

                    covered = rect - triangle + stones
                    if covered > K:
                        continue
                    required = stones + K - covered
                    result = min(result, required)
    return result

def solve2(N, M, K):
    result = K
    if N == 1:
        result = K
    else:
        for l in range(2, M+1):
            stones = 0
            covered = 0
            i = 1
            onside = 0
            while i * 2 <= l + 1:
                if i == 1:
                    stones += 2
                    covered += 2
                else:
                    b = min(N, 2*i-1)
                    if i * 2 == l + 1:
                        stones += 2
                        covered += b
                        if b == N:
                            onside += 1
                    else:
                        stones += 4
                        covered += b*2
                        if b == N:
                            onside += 2
                i += 1

            if covered > K:
                required = stones
            else:
                required = stones + K - covered
            result = min(result, required)

            a = min(N-1, (l-1)//2)
            b = min(l, N) - a - 1
            corners = [a, a, b, b]
            while sum(corners) > 0:
                corners.sort(reverse=True)
                stones += 1
                covered += corners[0]
                corners[0] -= 1
                
                if covered > K:
                    required = stones
                else:
                    required = stones + K - covered
                result = min(result, required)


    return result


fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N, M, K = map(int, fin.readline().split())
    N, M = min([N, M]), max([N, M])
    debug("Case #%d" % case)
    result = solve2(N, M, K)

    print("Case #%d: %s" % (case, result))