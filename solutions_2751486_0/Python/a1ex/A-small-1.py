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
    for i in range(L+1):
        for j in range(i+1,L+1):
            if consec(w[i:j]) >= n:
                ans += 1
    
    print "Case #%d: %s" % ((k+1), ans)

