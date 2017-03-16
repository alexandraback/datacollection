#!/usr/bin/python

import sys

data = file( sys.argv[1] ).read().splitlines()

l = data.pop( 0 )
NUMCASE = int(l)

def brute2( i, cur, cursteps ):
    global MAX
    key = ( i, cursteps )
    if i >= len( MOTE ):
        return 0
    v = MOTE[i]
    if key in MAX and True:
        if MAX[ key ] >= cur:
            return 999999999
#    print key, cur
    MAX[ key ] = cur
    s, newA = steps( cur, v )
        
    # del
    t1 = brute2( i + 1, cur,cursteps+1 ) + 1
    # increase
    t2 = brute2( i + 1, newA,cursteps+s ) + s
    if t1 < t2:
        return t1
    else:
        return t2

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

def calc( i, cur ):
    numedit = 0
    while i < len( MOTE ):
        v = MOTE[i]
        if cur > v:
            cur += v
            i += 1
            continue
        s, newA = steps( cur, v )
        if i < len( MOTE ) - 1:
            s2, newA2 = steps( cur, MOTE[i+1] )
            s3, newA3 = steps( newA, MOTE[i+1] )
            assert s2+1 > s + s3
            if s2 + 1 < s3 + s:
                assert False
            if s2 + 1 == s3 + s:
                assert False
                if newA2 > newA3:
                    # del
                    i+= 1
                    numedit += 1
                    continue
        if s >= len( MOTE ) - i:
            numedit += len( MOTE ) - i
            break
        cur = newA
        numedit += s
        i+=1
    return numedit

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
    MAX = {}
    if A == 1:
        print len( MOTE )
        continue
#    b = brute( 0, A )
#    print b
    bb = brute2( 0, A,0 )
    print bb
#    assert b == bb
#    print r, t
#    a = calc(r,t)
#    b = calc2(r,t)
#    c = calc3(r,t)
#    if a != c:
#        print r, t
#        print a, c
#        assert a == c
#    print c





