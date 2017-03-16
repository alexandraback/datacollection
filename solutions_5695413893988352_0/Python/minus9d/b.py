#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import itertools
from collections import Counter

def cvrt_q(S, cmb):
    idx = 0
    ret = ""
    for ch in S:
        if ch == '?':
            ret += str(cmb[idx])
            idx += 1
        else:
            ret += ch
    return ret
    

def solve():
    S1,S2 = input().split()
    q1 = S1.count('?')
    q2 = S2.count('?')
    
    nums = list(range(10))
    
    best = 1e20
    minimum_i = 1e20
    minimum_j = 1e20
    for i in itertools.product(nums, repeat=q1):

        T1 = cvrt_q(S1, i)
        for j in itertools.product(nums, repeat=q2):
            T2 = cvrt_q(S2, j)

            absv = abs(int(T1) - int(T2))
    
            if absv < best:
                best = absv
                minimum_i = T1
                minimum_j = T2
    
            elif absv == best:
                if T2 < minimum_j:
                    minimum_i = T1
                    minimum_j = T2
    print("{:} {:}".format(minimum_i, minimum_j))
                
        
        
def main():
    T = int(input())
    for t in range(T):
        print ("Case #" + str(t+1) + ": ", end="")
        solve()

main()

