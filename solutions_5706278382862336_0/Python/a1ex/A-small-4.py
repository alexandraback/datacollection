import sys, string
from copy import copy, deepcopy
import gmpy
import time
from fractions import gcd

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readfrac():
	return [int(x) for x in sys.stdin.readline().strip().split("/")]

def readint():
	return int(sys.stdin.readline())

T = readint()

def bits(n):
    b = 0
    while n > 0:
        n >>= 1
        b += 1
    return b

cache = {}
def solve(a,b):

    g = gcd(a,b)
    a = a/g
    b = b/g
    
    if (a,b) in cache:
        return cache[(a,b)]
        
    #~ print a,b

    bi = bits(b)-1
    if b != 1<<bi:
        cache[(a,b)] = None
        return None
    
    if a == b:
        cache[(a,b)] = 0
        return 0
    
    best = None
    for d in range(1, min(a,b-a)+1):
        sol = solve(a+d, b)
        if sol is not None:
            sol += 1
        if sol < best or best is None:
            best = sol
    #~ print best
    cache[(a,b)] = best
    return best
        

for t in range(T):
    a,b = readfrac()
    
    #~ print >> sys.stderr, t, a, b
    print ("Case #%d:" % (t+1)),
    
    s = solve(a,b)
    if s == None:
        print "impossible"
    else:
        print s
    #~ print >> sys.stderr, s
    #~ print a, b, bi, 1<<bi
