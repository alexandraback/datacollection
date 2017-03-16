#! /usr/bin/env python3
# -*- coding: utf8 -*-
# vim: expandtab ts=4 ai

from functools import reduce

def estimate(r,c):
    t  = ( 2*r + 1 ) * c
    t += c * ( c-1 ) * 2
    return t

def do_calc(r,t):
    c = 1
    e = estimate(r,c)
    while t >= e:
        d = estimate(r,c+1) - e
        
        if ( t/e ) > 100:
            c *= 10
        elif ((t-e)/d) > 2000:
            c += int(((t-e)/d)/5)
        else:
            c += 1

        e = estimate(r,c)
    return c-1

def main():
    for c in range(int(input())):
        (r,t) = map(int,input().split())
    
        judge = do_calc(r,t)
     
        print('Case #%d: %s' % ( c+1, judge ))

if __name__ == '__main__':
    main()
