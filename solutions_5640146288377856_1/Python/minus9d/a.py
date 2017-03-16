#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def lastone(C,W):
    ans = 0
    while not W <= C <= 2*W-1:
        ans += 1
        C -= W
    if C == W:
        ans += W
    else:
        ans += W + 1

    return ans

def another(R,C,W):
    ans = 0
    while C >= W:
        C -= W
        ans += 1
    return ans * R

def solve():
    R,C,W = map(int,input().split())

    ans = 0
    ans = lastone(C,W)
    if R > 1:
        ans += another(R-1,C,W)
    return ans

def main():
    T = int(input())
    for t in range(T):
        a = solve()
        print ("Case #" + str(t+1) + ":", a)

main()

