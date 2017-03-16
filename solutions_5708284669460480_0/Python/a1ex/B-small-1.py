#from __future__ import division
import sys, string
from copy import copy, deepcopy
import gmpy
import time
import itertools

import sys
sys.setrecursionlimit(1000000)

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

def readbinlist():
	return [int(x,2) for x in sys.stdin.readline().strip().split(" ")]

def readint():
	return int(sys.stdin.readline())

T = readint()

def count(typed, word):
    L = len(typed)
    l = len(word)
    c = 0
    for i in range(L-l+1):
        s = typed[i:i+l]
        if s == word:
            c += 1
    return c

def numberToBase(n, b, d):
    digits = []
    for i in range(d):
        digits.append(int(n % b))
        n /= b
    return digits[::-1]

def combinations_with_replacement(str, r):
    C = []
    L = len(str)
    for i in range(L ** r):
        b = numberToBase(i, L, r)
        #~ print b
        s = ""
        for k in b:
            s += str[k]
        C.append(s)
    
    return C

#~ print combinations_with_replacement("ABC", 2)
#~ raise SystemExit

for t in range(T):
    K,L,S = readlist()
    keyb = sys.stdin.readline().strip()
    word = sys.stdin.readline().strip()
    
    print >> sys.stderr, "Solving case #%d..." % (t+1)
    print ("Case #%d:" % (t+1)),
    
    #~ while len(keyb) < len(word):
        #~ keyb += keyb
    
    #~ print keyb, word
    
    cmax = 0
    ctotal = 0
    num = 0
    for b in combinations_with_replacement(keyb, S):
        b = "".join(b)
        #~ print b
        c = count(b, word)
        cmax = max(cmax, c)
        ctotal += c
        num += 1
    
    cavg = 1.0 * ctotal / num
    #~ print cmax, cavg, num, ctotal, cmax - cavg
    print cmax - cavg
