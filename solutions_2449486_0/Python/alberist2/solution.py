#!/usr/bin/python3
# -*- coding: utf-8 -*-

def solve():
    N,M = map(int,input().split())
    a = [list(map(int,input().split())) for _ in range(N)]
    changed = 0
    while changed<2 and a:
        changed += 1
        new_a = []
        m = min(map(min,a))
        for line in a:
            if set(line)!=set([m]):
                new_a.append(line)
            else:
                changed = 0
        a = list(zip(*new_a))
    if a:
        print ("NO")
    else:
        print ("YES")

if __name__=="__main__":
    T = int(input())
    for t in range(1,T+1):
        print("Case #%d:"%t,end=' ')
        solve()

