import string
import sys
import math
from itertools import *
import operator
import cPickle
from collections import Counter

class Tee:
    def __init__(self, file):
        self.file = file
        
    def write(self, str):
        sys.stdout.write(str)
        self.file.write(str)

    def close(self):
        self.file.close()

atz = [chr(x+ord('a')) for x in xrange(ord('z')-ord('a')+1)]

def simplifySet(s):
    r = ''
    pc = None
    for c in s:
        if (c != pc):
            pc = c
            r += c
    return r

def simplifySets(S):
    r = [simplifySet(x) for x in S]
    return r

def connectSimple(S):
    si = []
    mu = []
    for s in S:
        if len(s) == 1:
            si += [s]
        else:
            mu += [s]
            
    d = toDict(mu, -1)
    if (d is False):
        return False,0
    
    si,m = connectB({},si)
    if (si is False):
        return False,0
    
    c,m2 = connectB(d, si)
    if (c is False):
        return False,0
    
    return c,m

def toDict(S,i):
    r = {}
    for s in S:
        if (s[i] in r):
            return False
        else:
            r[s[i]] = s
    return r

def connectB(r,S):
    mult = {}
    for k in atz:
        mult[k] = 1
        
    for s in S:
        if (s[0] in r):
            s1 = r[s[0]]
            if (s1 is False):
                return False,0
            r[s[0]] = False
            s1 += s
            r[s[-1]] = s1
            mult[s[0]] += 1
        else:
            r[s[-1]] = s
            
    m = 1
    for x in mult.values():
        m *= math.factorial(x)
    
    r = [string.join(x, '') for x in r.values() if (x is not False)]
    return r,m

def connectE(r,S):
    mult = {}
    for k in atz:
        mult[k] = 1
        
    for s in S:
        if (s[-1] in r):
            s1 = r[s[-1]]
            if (s1 is False):
                return False,0
            r[s[-1]] = False
            s1 += s
            r[s[0]] = s1
            mult[s[-1]] += 1
        else:
            r[s[0]] = [s]
            
    m = 1
    for x in mult.values():
        m *= math.factorial(x)
    
    r = [string.join(x, '') for x in r.values() if (x is not False)]
    return r,m

def isValid(S):
    r = {}
    ls = None
    
    for s in S:
        if s != ls:
            ls = s
            if (s in r):
                return False
            else:
                r[s] = 1
    return True  

def solve(N,S):
    S = simplifySets(S)
    c,m1 = connectSimple(S)
    if (c is False):
        return False
    
    ll = 0
    nl = 1
    while (ll <> nl):
        c,m2 = connectB({}, c)
        if (c is False):
            return False
    
        c,m3 = connectE({}, c)
        if (c is False):
            return False
        
        ll = nl
        nl = len(c)
    
    if not isValid(string.join(c,'')):
        return False
    
    
    r = m1*math.factorial(len(c))
    
    return r


name = "test"
name = "B-small-attempt4"
#name = "A-large"

fin = open(name+".in", "r")
fout = open(name+".out", "w")
fout = Tee(fout)

T = int(fin.readline())

for t in range(1,T+1):
    N = [int(fin.readline())]
    S = [x.strip() for x in fin.readline().split()]

    r = solve(N,S);
    
    if (r is False):
        r = 0
    
    r = r % 1000000007

    print >> fout, "Case #{}: {}".format(t, r)

print "=== DONE ==="
