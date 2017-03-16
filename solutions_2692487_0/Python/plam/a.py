#!/usr/bin/python

import sys

data = file( sys.argv[1] ).read().splitlines()

l = data.pop( 0 )
NUMCASE = int(l)

def brute( i, cur ):
    if i >= len( MOTE ):
        return 0
    v = MOTE[i]
    s, newA = steps( cur, v )
    # del
    t1 = brute( i + 1, cur ) + 1
    # increase
    t2 = brute( i + 1, newA ) + s
    if t1 < t2:
        return t1
    else:
        return t2

def steps( A, v ):
    s = 0
    t = A
    while t <= v:
#        print ( s, t)
        s += 1
        t += t - 1
    t += v
#    print ( s, t)
    return ( s, t )

#print steps( 9, 100)
#exit(0)

for CASE in range(1,NUMCASE+1):
    print 'Case #%d:' % CASE,
    l = data.pop( 0 )
    A, N = [ int(x) for x in l.split(' ') ]
    l = data.pop( 0 )
    MOTE = sorted( [ int(x) for x in l.split(' ') ] )
#    print A, N
#    print MOTE
    numedit = 0
    if A == 1:
        print len( MOTE )
        continue
    b = brute( 0, A )
    print b
    if False:
        while len( MOTE ):
            v = MOTE.pop( 0 )
            if A > v:
                A += v
                continue
            s, newA = steps( A, v )
            if s >= len( MOTE ) + 1:
                numedit += len( MOTE ) + 1
                break
            A = newA
            numedit += s
        print numedit
        assert b == numedit
#    print r, t
#    a = calc(r,t)
#    b = calc2(r,t)
#    c = calc3(r,t)
#    if a != c:
#        print r, t
#        print a, c
#        assert a == c
#    print c





