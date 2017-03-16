#! /usr/local/bin/python
# -*- coding: utf-8 -*-

import math

def isPalindrome( number ):

    rev = number[ :: -1 ]

    return rev == number

if __name__ == '__main__':

    test = input()

    for t in range( test ):

        a, b = raw_input().split()
        a = int( a )
        b = int( b )

        cnt = 0

        visited = {}

        d = ( b - a ) + 1

        for x in range( d ):

            x = a + x


            y = int( math.sqrt( x ) )

            if x == y**2 and isPalindrome( str( y ) ):
                
                while isPalindrome( str( x ) ) and x <= b and x not in visited:
                    cnt = cnt + 1
                    visited[ x ] = True
                    x = x**2
            
        print "Case #%d: %d" % ( t + 1, cnt )


