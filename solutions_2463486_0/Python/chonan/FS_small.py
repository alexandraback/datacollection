#! /usr/bin/env python3
# -*- coding: utf8 -*-
# vim: expandtab ts=4 ai

import math

LIMIT = int(math.sqrt(10**3))+1
FAIR_SQUARE = []

def chk_palindrome(n):
    if n <= 0:
        return False
    if n < 10:
        return True
    if n < 100:
        return ( (n%11)==0 )

    s = list(str(n))
    t = s[:]
    t.reverse()
    return (s==t)

def do_calc(a,b):
    count = 0
    for n in FAIR_SQUARE:
        if ( ( n >= a ) and ( n <= b ) ):
            count += 1
    return count

def main():
    global FAIR_SQUARE

    for i in range(1,LIMIT+1):
        if chk_palindrome(i):
            square = i * i
            if chk_palindrome(square):
                FAIR_SQUARE.append(square)
#    print(FAIR_SQUARE)

    for c in range(int(input())):
        (a,b) = map(int,input().split())

        judge = do_calc(a,b)
     
        print('Case #%d: %s' % ( c+1, judge ))

if __name__ == '__main__':
    main()
