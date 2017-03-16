# -*- coding: utf-8 -*-
"""
Created on Sat Apr 30 19:25:23 2016

@author: Eidan Cohen
"""

def realize(c):
    if len(c) == 0:
        yield 0
    elif c[-1] != '?':
        for x in realize(c[:-1]):
            yield 10*x + int(c[-1])
    else:
        for i in range(10):
            for x in realize(c[:-1]):
                yield 10*x + i
        
def leading_zeros(s, l):
    return "0"*(l - len(str(s))) + str(s) 

def solve(c,j):
    scorelen = len(c)
    best_key = (pow(10, len(c) + len(j)), 0, 0)
    for cn in realize(c):
        for jn in realize(j):
            key = (abs(cn - jn), cn, jn)
            best_key = min(key, best_key)
    diff, cn, jn = best_key
    return "{0} {1}". format(leading_zeros(cn, scorelen), leading_zeros(jn, scorelen))
    
def main():
    t = int(input())
    for i in range(1,t+1):
        s1,s2 = input().rstrip().split(" ")
        print('Case #{0}: {1}'.format(i, solve(s1,s2)))

if __name__ == '__main__':
    main()

