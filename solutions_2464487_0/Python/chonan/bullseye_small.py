#! /usr/bin/env python3
# -*- coding: utf8 -*-
# vim: expandtab ts=4 ai

from functools import reduce

def do_calc(r,t):
    c = 0
    while t >= (2*r + 1):
        c += 1
        t -= 2*r + 1
        r += 2
    return c

def main():
    for c in range(int(input())):
        (r,t) = map(int,input().split())
    
        judge = do_calc(r,t)
     
        print('Case #%d: %s' % ( c+1, judge ))

if __name__ == '__main__':
    main()
