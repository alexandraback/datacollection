#from __future__ import division
import sys, string
import itertools
from math import *

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

T = int(sys.stdin.readline())

D = {}
def add(Q, elem):
    global D
    X,Y,FOO,BAR = elem
    if (X,Y) not in D:
        D[X,Y] = True
        Q.append(elem)

for k in range(T):
    
    X,Y = readlist()
    print >> sys.stderr, k,X,Y
    
    Q = [(0,0,1,-1)]
    i = 0
    D = {}
    
    ans=""
    while i < len(Q):
         current = Q[i]
         x,y,d,p = current
         #~ print >> sys.stderr, k,x,y
         
         if (x,y) == (X,Y):
             #~ print "bingo"
             ans = ""
             while p >= 0:
                 elem = Q[p]
                 xn,yn = x,y
                 x,y,d,p = elem
                 #~ print x,y
                 
                 move = "X"
                 if xn>x: move = "E"
                 elif xn<x: move = "W"
                 elif yn>y: move = "N"
                 elif yn<y: move = "S"
                 ans = move + ans
             break
         
         if abs(x - X) < 1000 and abs(y - Y) < 1000:
             
             add(Q, (x + d, y, d+1, i))
             add(Q, (x - d, y, d+1, i))
             add(Q, (x, y+d, d+1, i))
             add(Q, (x, y-d, d+1, i))
             #~ print len(Q)
         
         i += 1
    
    
    print "Case #%d: %s" % ((k+1), ans)

