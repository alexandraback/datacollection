#!/usr/bin/python3

def get(r, k):
   return (k + 2 * r * k + 2 * k * (k - 1))

def solve(tc):
    r, t = map(int, input().strip().split())
    a = 0
    b = 10**20
    while b - a > 1:
        m = (a + b) // 2
        if (get(r, m) <= t):
            a = m
        else:
            b = m
    print("Case #%d: %d" % (tc, a))

T = int(input())
for i in range(T):
    solve(i + 1)
