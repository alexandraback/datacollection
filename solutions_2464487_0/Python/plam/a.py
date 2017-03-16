#!/usr/bin/python

import sys

data = file( sys.argv[1] ).read().splitlines()

l = data.pop( 0 )
N = int(l)

def calc( r, t ):
    amt = 0
    rings = 0
    while amt < t and r >= 1:
#        print amt, r
        amt += (2*r) + 1
        if amt > t:
            break
        r += 2
        ans = amt
        rings += 1
    return rings

for CASE in range(1,N+1):
    print 'Case #%d:' % CASE,
    l = data.pop( 0 )
    r, t = l.split(' ')
    r=int(r)
    t=int(t)
#    print r, t
    a = calc(r,t)
    print a





