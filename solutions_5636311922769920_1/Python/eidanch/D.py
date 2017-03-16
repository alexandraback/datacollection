# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 03:19:19 2016

@author: Eidan Cohen
"""

from functools import reduce

def get_positions(K,C,S):
    # For testing only
    bases = []
    for i in range(K+1):
        base = "0"*i + "1" + "0"*(K-i-1)
        bases.append(base)
    print(bases)
    covered = 0
    i = 0
    while covered < K:
        x = map(lambda z: int(develop(z, C, "1","0"),2), bases[i*C:min((i+1)*C, K)])
        r = reduce(lambda x,y: x & y , x)
        rs = "0"*(pow(K,C) - len(bin(r)[2:])) + bin(r)[2:]
        print(rs)
        i += 1
        covered += C
    

def solve(K,C,S):
    if K > S*C:
        return "IMPOSSIBLE"
    else:
        result = []
        covered = 0
        for i in range(S):
            p = 0
            for j in range(min(C,K)):
                p += (i*C+j)*pow(K,C-1-j)
                covered += 1
                if covered == K:
                    break
            result.append(p + 1)
            if covered == K:
                break
    return ' '.join(map(str,result))

def main():
    T = int(input())
    for i in range(1,T+1):
        K,C,S = map(int, input().strip().split())
        print("Case #%d: %s" % (i, solve(K,C,S)))
        
def step(original,current,gold="G", lead="L"):
    r = ""    
    for m in current:
        if m == gold:
            r += len(original)*gold
        else:
            r += original
    return r
            
def develop(original, steps,gold="G", lead="L"):
    current = original
    for i in range(steps-1):
        current = step(original, current, gold, lead)
    return current

if __name__ == '__main__':
    main()