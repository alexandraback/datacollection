#!/usr/bin/env python
import sys
from collections import Counter
from itertools import combinations

def pos(b):
    r = [ '0', '9' ]
    if b != '?':
        if b != '9':
            r.append( str( int(b) + 1) )
        if b != '0':
            r.append( str( int(b) - 1) )
        r.append(b)
    return r


def gen(a, b):
    rlt = []
    tmp = []

    for i in range(len(a)):
        if a[i] != '?':
            if len(tmp) == 0:
                tmp = [ a[i] ]
            else:
                tmp = [ _+(a[i]) for _ in tmp ]
        else:
            if len(tmp) == 0:
                tmp = [  p  for p in pos(b[i] )   ]
            else:
                tmp = [ _+(p)  for _ in tmp for p in pos(b[i]) ] 
    
    rlt= [ int( ''.join(i) ) for i in tmp ]
    return rlt

def comfun( a, b):
    print a, b
    if a[1] == b[1] :
        return cmp(a[2], b[2] )
    else:
        return cmp(a[1], b[1] )
   
def game(scores):
    
    a  = [ _ for _ in scores[0] ]
    b  = [ _ for _ in scores[1] ]

    n = len(a)

    rlt = {}

    for ai in gen( a, b):
        for bi in gen(b, a ):
            t = abs(ai - bi )
            if rlt.has_key(t):
                rlt[t].append( (ai, bi ) )
            else:
                rlt[t] = [ ( ai, bi ) ]

    amin = min( rlt.keys() )

    tmp2 = rlt[amin]
    
    myrlt = (10000, 10000)
    for i, j in tmp2:
        if myrlt[0] > i:
            myrlt = (i,j)
        if myrlt[0] == i :
            if myrlt[1] > j:
                myrlt = (i, j )

        

    #i, j = map( str,    sorted( tmp2, cmp=comfun )[0] )
    i, j  = map( str,  myrlt )
    i = i.zfill(n)
    j = j.zfill(n)

    return "%s %s" % (i, j)


            
 

fin = open(sys.argv[1], 'r')
cases = int( fin.readline().strip() )
for i  in range(cases):
    scores  = fin.readline().strip().split()
        
    print "Case #%d: %s" % ( i+1 , game(scores) )
