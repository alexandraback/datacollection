#!/usr/bin/python3

import math
import sys
from heapq import heappush, heappop
import math

X =0 
Y = 0

class point():
    def __init__(self, x, y, parent, dest,i):
        self.x = x
        self.y = y
        self.parent = parent
        self.dest = dest
        self.i = i
        global X,Y
        self.dist = math.sqrt(float(X-self.x)**2+float(Y-self.y)**2) 
    def r(self):
        global X,Y
        return self.x==X and self.y == Y
    def __le__(self,p):
        return self.dist < p.dist
        #return self.i < p.i

def testpush(h,p):
    for i in h:
        if i.x == p.x and i.y == p.y: return
    h.append(p)

def case():
    global X,Y
    X, Y = [int(x) for x in sys.stdin.readline().split()]
    start = point(0,0,None,"",0)
    si = 0
    h = []
    #heappush(h, start)
    h.append(start)
    pos = 0
    dp = None
    while dp == None:
        #p = heappop(h)
        p = h[pos]
        pos += 1
        #print("popped", (p.x,p.y))
        i = p.i + 1
        #if i>3: break
        p1 = point(p.x+i,p.y,p,'E',i)
        p2 = point(p.x-i,p.y,p,'W',i)
        p3 = point(p.x,p.y+i,p,'N',i)
        p4 = point(p.x,p.y-i,p,'S',i)
        if(p1.r()): dp = p1
        if(p2.r()): dp = p2
        if(p3.r()): dp = p3
        if(p4.r()): dp = p4
        #heappush(h,p1)
        #heappush(h,p2)
        #heappush(h,p3)
        #heappush(h,p4)
        testpush(h,p1)
        testpush(h,p2)
        testpush(h,p3)
        testpush(h,p4)
        #h.extend([p1,p2,p3,p4])
    s = ""
    while dp != None:
        s += dp.dest
        dp = dp.parent
    return s[::-1]

def case1():
    X, Y = [int(x) for x in sys.stdin.readline().split()]
    s =""
    if X > 0: s += "WE"*X
    if X < 0: s += "EW"*(-X)
    if Y > 0: s+= "SN"*Y
    if Y < 0: s+= "NS"*(-Y)
    return s
    
T = int(sys.stdin.readline())
for i in range(1,T+1):
    print("Case #%s: %s" % (i, case1()))
    

