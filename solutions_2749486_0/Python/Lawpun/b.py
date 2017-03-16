#!python
from __future__ import print_function
from heapq import *
from collections import *
from itertools import *
import sys, random

sys.setrecursionlimit(10000)

def gets():
    try:
        return raw_input()
    except EOFError:
        return None

def getint():
    return int(gets())

def getints():
    return [int(x) for x in gets().split()]

def solve(x,y):
    q = deque()
    q.append((0,0,None,None,None,0))
    prev = {}
    vis = set()

    while len(q) > 0:
        ux, uy, px, py, direction, k = q.popleft()
        if not (ux,uy) in vis:
            vis.add((ux,uy))
            prev[(ux,uy)] = (px,py,direction)
        else:
            continue

        #print(ux,uy,px,py,k+1)
        if ux == x and uy == y:
            break

        nx,ny = ux+k+1, uy
        if (nx,ny) not in vis:
            q.append((nx,ny,ux,uy,'E',k+1))
        nx,ny = ux-k-1, uy
        if (nx,ny) not in vis:
            q.append((nx,ny,ux,uy,'W',k+1))
        nx,ny = ux, uy+k+1
        if (nx,ny) not in vis:
            q.append((nx,ny,ux,uy,'N',k+1))
        nx,ny = ux, uy-k-1
        if (nx,ny) not in vis:
            q.append((nx,ny,ux,uy,'S',k+1))
    
    stk = []
    ux, uy = x, y
    while ux != 0 or uy != 0:
        px,py,direction = prev[(ux,uy)]
        #print(px,py,direction)
        stk.append(direction)
        ux, uy = px,py

    stk.reverse()
    return ''.join(stk)



T = getint()
for ic in xrange(T):
    x,y = getints()
    ans = solve(x,y)
    print("Case #{0}: {1}".format(ic+1, ans))
