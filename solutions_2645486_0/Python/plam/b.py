#!/usr/bin/python

import sys

data = file( sys.argv[1] ).read().splitlines()

l = data.pop( 0 )
N = int(l)

CACHE = {}

def MAX( i, CURE ):
   max = 0
   if i >= N:
       return 0
   if CURE <= 0:
       return 0
   if CURE > E:
       CURE = E
   for e in range(0, CURE+1):
       if CURE-e+R < 0:
           continue
       m = V[i]*e + MAX(i+1,CURE-e+R)
       if m > max:
#           print 'max is',i,e,m
           max = m
   return max

for CASE in range(1,N+1):
    print 'Case #%d:' % CASE,
    l = data.pop( 0 )
    E, R, N = l.split(' ')
    E = int(E)
    R = int(R)
    N = int(N)
#    print E, R, N
    l = data.pop( 0 )
    VT = l.split(' ')
    V = []
    for v in VT:
        V.append( int(v))
#    print V
    ans = MAX(0,E)
    print ans




