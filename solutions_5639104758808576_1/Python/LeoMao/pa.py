#! /usr/bin/env python

T = int(input())

for t in range(1, T+1):
    n, s = input().split()
    n = int(n)
    ss = [ord(x) - ord('0') for x in s]
    need = 0
    now = 0
    for i, x in enumerate(ss):
        if now < i:
            need += i - now
            now = i
        now += x

    print("Case #{}: {}".format(t, need))
        
