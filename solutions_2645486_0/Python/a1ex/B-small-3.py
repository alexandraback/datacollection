#from __future__ import division
import sys, string
import itertools
from math import *

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

T = int(sys.stdin.readline())

E = None
R = None
N = None
V = None

def sim(energy):
    Elev = E
    total = 0
    for i,e in enumerate(energy): # direct sim
        if e > Elev:
            print "whoops", i, e, Elev
            return None
        total += e * V[i]
        Elev -= e
        Elev += R
        Elev = min(Elev, E)
    return total, Elev

cache = {}

ES = []
def solve(e0, i0):
    global cache
    
    if i0 == N-1:
        return e0 * V[i0]
    
    if e0 < 0: return 0
    
    if (e0,i0) in cache:
        return cache[e0,i0]
    
    G = []
    for i in range(e0+1):
        G.append(solve(min(E,e0-i+R), i0+1) + i * V[i0])
    #~ print G
    ans = max(G)
    cache[e0,i0] = ans
    ES[i0] = G.index(ans)
    return ans


for k in range(T):
    print >> sys.stderr, k
    
    E, R, N = readlist()
    V = readlist()
    cache = {}
    ES = range(N)
    
    ans = solve(E, 0)
    #~ print ES, sim(ES)
    
    print "Case #%d: %s" % ((k+1), ans)

