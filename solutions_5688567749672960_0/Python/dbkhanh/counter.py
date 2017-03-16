#!/usr/bin/env python

import os, sys

cache = {}
def solve(N):
    if N in cache: return cache[N]
    if N == 1: return 1
    if N-1 in cache:
        a = cache[N-1]
    else:
        a = solve(N-1)
        cache[N-1] = a

    flip = int(str(N)[::-1])
    if flip >= N or N%10 == 0:
        # print(N-1)
        return 1 + a

    if flip in cache:
        b = cache[flip]
    else:
        b = solve(flip)
        cache[flip] = b

    cache[N] = 1 + min(a, b)
    # if (a < b): print(N-1)
    # else: print(flip)
    return cache[N]

def main():
    for N in range(1, 1000001):
        solve(N)
        # print("solve({}) = {}".format(N, solve(N)))
    lines = open(sys.argv[1]).read().rstrip().splitlines()
    T = int(lines[0])
    for case in range(1, T+1):
        answer = solve(int(lines[case]))
        print("Case #{}: {}".format(case, answer))

if __name__ == "__main__":
    main()
