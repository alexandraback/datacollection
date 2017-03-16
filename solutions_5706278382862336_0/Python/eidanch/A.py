# -*- coding: utf-8 -*-
"""
Created on Sun May 11 12:02:30 2014

@author: eidanch
"""

from fractions import gcd

def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int,s.split(' ')))

def standard_input():
    T = int(get_line())
    for i in range(T):
        lst = get_line().split('/')
        yield (i+1,(int(lst[0]),int(lst[1])))

def f(P,Q):
    if P*2 >= Q:
        return 1
    return 1 + f(P, Q/2)
        

def handle_case(case):
    P,Q = case
    d = gcd(P,Q)
    P /= d
    Q /= d
    if Q & (Q - 1) > 0:
        return 'impossible'
    return str(f(P,Q))
    
        
def main():
    for i,case in standard_input():
        print "Case #%d: %s" %(i,handle_case(case))        

if __name__ == '__main__':
    main()
    