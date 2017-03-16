from __future__ import division
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

def overlap(word):
    for i in range(1, len(word)+1):
        prefix = word[:-i]
        suffix = word[i:]
        if prefix == suffix:
            return i

for t in range(T):
    K,L,S = readlist()
    keyb = sys.stdin.readline().strip()
    word = sys.stdin.readline().strip()
    
    print >> sys.stderr, "Solving case #%d..." % (t+1)
    print ("Case #%d:" % (t+1)),
    
    impossible = False
    for l in word:
        if l not in keyb:
            impossible = True
            break
    
    if impossible:
        print "0.0"
        continue
    
    p = 1 + S - L
    for l in word:
        p *= keyb.count(l) / len(keyb)
    #~ print p
    
    ovr = overlap(word)
    max = 1 + (S - L) // ovr
    print max - p
