#!/usr/bin/env python

import os, sys

def flip(n):
    return int(str(n)[::-1])

m = {}
def prep():
    d = [9, 19, 109, 199, 1099, 1999, 10999, 19999,
         109999, 199999, 1099999, 1999999, 10999999, 19999999]
    m[1] = 1
    for i in range(2, 16):
        m[i] = m[i-1] + d[i-2]
    # print(m)

def solve(N):
    if N % 10 == 0: return solve(N-1) + 1
    num_digits = len(str(N))
    if num_digits == 1: return N
    count = m[num_digits]
    n = (10 ** (num_digits-1))
    # print(n, count)
    if n == N: return count
    x = int(str(N)[:num_digits/2][::-1])
    n += x
    count += x
    # print(n, count)
    if n == N: return count
    f = flip(n)
    if f != n:
        n = flip(n)
        count += 1
    # print(n, count)
    if n == N: return count
    x = N - n
    count += x
    # print(n, count)
    return count
    # print(count, n)

def main():
    lines = open(sys.argv[1]).read().rstrip().splitlines()
    T = int(lines[0])
    for case in range(1, T+1):
        answer = solve(int(lines[case]))
        print("Case #{}: {}".format(case, answer))

if __name__ == "__main__":
    prep()
    main()
