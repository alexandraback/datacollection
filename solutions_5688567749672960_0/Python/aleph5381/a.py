#!/usr/bin/env python3

import sys
rl = lambda: sys.stdin.readline()
T = int(rl())

def reverse(n):
    return int(str(n)[::-1])


data = []

def foo(x, n):
    global data
    while True:
        if x == n:
            return
        cnt = data[x] 
        rx = reverse(x)
        if rx <= n and rx > x+1:
            data[rx] = min(data[rx], cnt+1)
        data[x+1] = min(data[x+1], cnt+1)
        x += 1

#def do(x, n, cnt):
#    while True:
#        if x == n:
#            return cnt
#        cnt += 1
#        rx = reverse(x)
#        if rx <= n and rx > x+1:
#            x = rx
#        else:
#            x = x+1

def solve(casei):
    n = int(rl())
    global data
    data = [i for i in range(n+1)]
    foo(1, n)
    ans = data[n]
    print("Case #{}: {}".format(casei, ans))

for i in range(1, T+1):
    solve(i)
