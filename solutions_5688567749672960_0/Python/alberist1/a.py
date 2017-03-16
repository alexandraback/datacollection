#!/usr/bin/pypy3
# -*- coding: utf-8 -*-

def solve():
    n = int(input())
    cnt = 1
    while n > 1:
        if n%10==0 or n < 10:
            cnt += 1
            n -= 1
            continue
        if len(str(n-2)) < len(str(n)):
            cnt += 1
            n -= 1
            continue
        s = str(n)
        right = s[len(s)//2:]
        sub = int(right) - 1
        if sub == 0:
            n = int(''.join(reversed(str(n))))
            cnt += 1
            continue
        n -= sub
        cnt += sub
    return cnt

if __name__=="__main__":
    T = int(input())
    for t in range(1,T+1):
        print("Case #%d:"%t,solve())

