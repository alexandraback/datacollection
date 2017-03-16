#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def solve():
    R,C,W = map(int,input().split())
    ans = 0
    while not W <= C <= 2*W-1:
        ans += 1
        C -= W
    if C == W:
        ans += W
    else:
        ans += W + 1

    return ans

def main():
    T = int(input())
    for t in range(T):
        a = solve()
        print ("Case #" + str(t+1) + ":", a)

main()

