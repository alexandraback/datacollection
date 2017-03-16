#from __future__ import division
import sys, string
import itertools
from math import *

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

T = int(sys.stdin.readline())

def isvowel(c):
    return c in ['a', 'e', 'i', 'o', 'u']
    
def consec(s):
    x = 0
    m = 0
    for c in s:
        if isvowel(c):
            m = max(m, x)
            x = 0
        else: x += 1
    m = max(m, x)
    return m;
    
for k in range(T):
    print >> sys.stderr, k
    
    w, n = sys.stdin.readline().strip().split(" ")
    n = int(n)
    L = len(w)
    
    ans = 0
    count = 0
    C = []
    lastj = 1+n-3
    for j in range(L):
        c = w[j]
        if isvowel(c):
            count = 0
        else:
            count += 1
            if count >= n:
                a,b = lastj-1 +3-n , j+1
                mul = b - a - n + 1
                #~ print L-j, a, b, mul
                delta = (L - j) * mul
                ans += delta
                C.append(delta)
                lastj = j
    #~ print C
    
    print "Case #%d: %s" % ((k+1), ans)

