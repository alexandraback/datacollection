# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 03:19:19 2016

@author: Eidan Cohen
"""

def solve(K,C,S):
    if K == S:
        result = [1+i*pow(K,C-1) for i in range(S)]
    return ' '.join(map(str,result))

def main():
    T = int(input())
    for i in range(1,T+1):
        K,C,S = map(int, input().strip().split())
        print("Case #%d: %s" % (i, solve(K,C,S)))
        

if __name__ == '__main__':
    main()