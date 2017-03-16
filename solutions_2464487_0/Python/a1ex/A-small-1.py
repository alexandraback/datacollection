#from __future__ import division
import sys, string
import itertools
from math import *

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

T = int(sys.stdin.readline())

def area(i):
    return i*2-1

def suma(n, a, d):
    return n * (2*a + (n-1)*d) / 2

# how much paint we need for n circles starting at R?
def paint(n, R):
    if R % 2:
        return suma(n+R/2, 3, 4) - suma(R/2, 3, 4)
    else:
        return suma(n+R/2, 1, 4) - suma(R/2, 1, 4)

def bins(lo, hi, R, T):
    if hi <= lo+1:
        return lo
    
    m = int((lo+hi)/2)
    enough = paint(m, R) <= T
    #~ print lo, hi, m, enough
    if enough:
        return bins(m, hi, R, T)
    else:
        return bins(lo, m, R, T)

for k in range(T):
    print >> sys.stderr, k
    
    R, T = readlist()
    
    #~ print R,T
    
    ans = bins(1, 1e100, R, T)
    
    print "Case #%d: %s" % ((k+1), ans)

