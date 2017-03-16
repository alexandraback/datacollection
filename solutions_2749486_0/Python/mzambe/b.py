#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import array
import math

def solve( x, y ):
    res = ""
    xord = "EW"
    xfin = "E"
    yord = "SN"

    if ( x < 0 ):
      xord = "WE"
      xfin = "W"

    if ( y < 0 ):
      yord = "NS"

    for i in xrange( abs(x) - 1 ):
      res += xord

    if ( x != 0 ):
      res += xfin

    for i in xrange( abs(y) ):
      res += yord

    return res

def main():
  T = int(raw_input())
  for i in xrange( T ):
    strin = raw_input()
    #print strin
    lstin = map( int, strin.split(' ') )
    x = lstin[ 0 ]
    y = lstin[ 1 ]
    print 'Case #'+str(i+1)+':', solve( x, y )

if __name__ == '__main__':
    main()
