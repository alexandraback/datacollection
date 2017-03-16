#!/usr/bin/env python

import sys, operator as op, itertools as itt, math

def solve ( R, C, M ):
    reverse = lambda i: i
    if  R > C:
        R, C = C, R
        reverse = lambda i: zip ( *i )
    N = R*C
    E = N - M
    if N == 1:
        assert M == 0
        return [[0]]
    elif R == 1:
        game = [0]*E + [1]*M
        return reverse( [ game ])
    elif R == 2:
        if E == 1:
            game = [ [1] * C for i in xrange(2) ] 
            game[0][0] = 0
            return reverse ( game )
        elif E & 1 or E == 2:
            return
        else:
            assert ((E&1)==0) and ((M&1)==0)
            E, M = E/2, M/2
            assert E + M == C
            game = [ [0]*E + [1]*M for i in xrange(2) ]
            return reverse ( game )
    else:
        if E == 1:
            game = [ [1] * C for i in xrange(R) ]
            game[0][0] = 0
            return reverse ( game )
        elif E in frozenset ( ( 2, 3, 5, 7 ) ):
            return
        else:
            x = int ( E ** 0.5 ) if R*R > E else R
            if x*x<E: x = min(x+1, R)
            y = E / x
            z = E - x*y
            rx, ry = R-x, C-y
            #print "R,C,M,E={0},{1},{2},{3}   x,y,z={4},{5},{6}".format( R,C,M,E,x,y,z )
            game = [ [0]*y + [1]*ry for i in xrange(x) ] + [ [1]*C for i in xrange(rx) ]
            #print game
            if z == 1:
                #print x-1, y-1, game[x-1][y-1]
                game[x-1][y-1] = 1
                z += 1
            #print game
            #print z
            for row in game[:z]:
                row[y] = 0
            return reverse ( game )

def verify ( game, R, C, M ):
    #print game
    if not len(game) == R: return False
    if not all( ( len(row) == C for row in game ) ): return False 
    if not sum ( map ( sum, game ) ) == M: return False
    Z = [[0]*C for j in xrange(R) ]
    for x in xrange(R):
        for y in xrange(C):
            if game[x][y]:
                for i, j in itt.product ( (x-1, x, x+1), (y-1, y, y+1) ):
                    if i >= 0 and j >= 0 and i < R and j < C:
                        Z[i][j] += 1
    #print "Z:\n" + "\n".join( map(str, Z) )
    q, E = set(), set()
    q.add ( (0, 0) )
    while q:
        p = q.pop()
        x, y = p
        E.add(p)
        for i, j in itt.product ( (x-1, x, x+1), (y-1, y, y+1) ):
            p = (i,j)
            if i >= 0 and j >= 0 and i < R and j < C :
                if game[i][j]: continue
                if Z[i][j]: E.add(p)
                if (p not in q) and (p not in E):
                    q.add(p)
    #print "E:", len(E), E
    if not len(E) == R*C-M:
        return False
    return True

def myprint ( game ):
    #print game
    P = lambda row:  [ ( "*" if i else "." ) for i in row ]
    G = map ( P, game )
    G[0][0] = "c"
    for g in G:
        print "".join ( g )


F = sys.stdin
T = int( F.next() )

for i in xrange ( 1, T+1 ):
    R, C, M = map ( int, F.next().strip().split() )
    print "Case #{0}:".format ( i )
    game = solve ( R, C, M )
    if game != None:
        myprint ( game )
        assert verify ( game, R, C, M )
    else:
        print "Impossible"

