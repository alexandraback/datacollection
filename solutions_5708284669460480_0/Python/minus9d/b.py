#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from itertools import *

def solve():
    K,L,S = map(int,input().split())
    keys = input()
    target = input()
    
    mx = 0
    cnt_sum = 0
    rep = 0
    for c in product(keys, repeat=S):
        rep += 1
        s = "".join(c)
        # print(s)
        cnt = 0
        for i in range(len(s)):
            subs = s[i:i+L]
            # print ("sub: ", subs)
            if subs == target:
                cnt += 1
        mx = max(cnt, mx)
        cnt_sum += cnt
        # print("  c, cnt = ", c, cnt)

    # print("rep, cnt_sum, mx = ", rep, cnt_sum, mx)
    ans = ((mx * rep) - cnt_sum) / rep
    return  ans

def main():
    T = int(input())
    for t in range(T):
        a = solve()
        print ("Case #{0}: {1:.10f}".format(t+1, a))
        #print ("Case #" + str(t+1) + ":", a)

main()

