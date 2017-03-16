#! /usr/bin/env python3
# -*- coding: utf8 -*-
# vim: expandtab ts=4 ai

from functools import reduce

def do_calc(n,m,normpat):
    transpat = list(map(list, zip(*normpat)))
    normmax = []
    transmax = []

    for i in range(n):
        normmax.append( max(normpat[i]) )
    for j in range(m):
        transmax.append( max(transpat[j]) )
    
    for i in range(n):
        for j in range(m):
            if ( ( normpat[i][j] < normmax[i] ) and 
                 ( normpat[i][j] < transmax[j] ) ):
                return 'NO'
    return 'YES'

def main():
    for c in range(int(input())):
        pattern = []
        (n,m) = map(int,input().split())

        for l in range(n):
            line = list(map(int,input().split()))
            pattern.append(line)

        judge = do_calc(n,m,pattern)
     
        print('Case #%d: %s' % ( c+1, judge ))

if __name__ == '__main__':
    main()
