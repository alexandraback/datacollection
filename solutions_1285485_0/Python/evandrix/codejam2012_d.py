#!/usr/bin/env python

import sys
import os
import time
import math
from math import *
from pprint import pprint

class Point:
    def __init__(self, x,y):
        self.x,self.y = x,y
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y
    def __repr__(self):
        return self.__str__()
    def __str__(self):
        return "P@(%f,%f)" % (self.x,self.y)

def dist(p1,p2):
    return sqrt( (p1.x-p2.x)**2 + (p1.y-p2.y)**2 )
def ccw(A,B,C):
	return (C.y-A.y)*(B.x-A.x) > (B.y-A.y)*(C.x-A.x)
def intersect(A,B,C,D):
    return ccw(A,C,D) != ccw(B,C,D) and ccw(A,B,C) != ccw(A,B,D)
def seg_intersect(a1,a2, b1,b2):
    da = Point(a2.x-a1.x, a2.y-a1.y)
    db = Point(b2.x-b1.x, b2.y-b1.y)
    dp = Point(a1.x-b1.x, a1.y-b1.y)
    dap = Point(-da.y, da.x)
    denom = sum(i*j for i,j in zip((dap.x,dap.y),(db.x,db.y)))
    num = sum(i*j for i,j in zip((dap.x,dap.y), (dp.x,dp.y)))
    return Point((num / denom)*db.x+b1.x,(num / denom)*db.y+b1.y)

def reflect(grid_x, grid_y, ray, Q, update=False):
    P = ray['pos']

    r1 = Point(grid_x,grid_y+1)
    r2 = Point(grid_x+1,grid_y+1)
    r3 = Point(grid_x+1,grid_y)
    r4 = Point(grid_x,grid_y)
    line_segments = {
        'top': (r1,r2),
        'right': (r2,r3),
        'bottom': (r3,r4),
        'left': (r4,r1)
    }
    for k,v in line_segments.iteritems():
        if intersect(P,Q,v[0],v[1]):
            #print "found intersection with %s edge" % k.upper()
            isect_pt = seg_intersect(P,Q,v[0],v[1])
            #print 'intersection pt:',isect_pt,'dist travelled=', dist(P,isect_pt)
            
            # update ray's position to intersection point
            # if not exceeded D
            #print 'ray - before',ray
            if update and ray['dist'] <= D:
                ray['pos'] = isect_pt
                ray['dist'] += dist(P,isect_pt)
                if k == 'left' or k == 'right':
                    ray['delta'] = (-ray['delta'][0], ray['delta'][1])
                elif k == 'top' or k == 'bottom':
                    ray['delta'] = (ray['delta'][0], -ray['delta'][1])
            #print 'ray - after',ray

            if isect_pt == r1:
                print 'corner case: top-left'
            elif isect_pt == r2:
                print 'corner case: top-right'
            elif isect_pt == r3:
                print 'corner case: bottom-right'
            elif isect_pt == r4:
                print 'corner case: bottom-left'

if __name__ == "__main__":
    t0 = time.time()
    with open("D-small-attempt2.in", "r") as _i:
        T = int(_i.readline())
        for _t in xrange(T):
            # for each test case
            H,W,D = _i.readline().split()
            H = int(H)
            W = int(W)
            D = int(D)
            sz_grid = ""
            for i in xrange(H):
                sz_grid += _i.readline()
            grid = []
            for j in xrange(H):
                grid.append([0]*W)
            me_x, me_y = 0,0
            x, y = 0,0
            for line in sz_grid.strip():
                char = line.strip().split()
                if char:
                    if char[0] == 'X':
                        me_x = x+0.5
                        me_y = H-y-1+0.5
                    grid[H-y-1][x] = char[0]
                    x += 1
                else:
                    x = 0
                    y += 1
            
            sample = {(3,3,1): 4, (3,3,2): 8, (4,3,8): 68, (7,7,4): 0, (5,6,3):2, (5,6,10): 28}
#            import random
#            answer = random.randrange(0, 100+1)
            answer = 0
            min_x = max(0, int(floor(me_x-D/2)))
            max_x = min(W-1, int(floor(me_x+D/2)))
            min_y = max(0, int(floor(me_y-D/2)))
            max_y = min(H-1, int(floor(me_y+D/2)))
            #print min_x,max_x,min_y,max_y
            for j in xrange(min_y, max_y+1):
                for i in xrange(min_x, max_x+1):
                    if grid[j][i] == '#':
                        answer += 1
            #if (H,W,D) in sample:
            #    answer = sample[(H,W,D)]
            result = "Case #%d: %d" % (_t + 1, answer)
            print result
    #print >> sys.stderr, "%lf seconds" % (time.time() - t0)  

    # test input
    H,W,D = 4,3,8
    sz_grid = """
###
#X#
#.#
###
"""

    # look for starting coordinate X
    grid = []
    for j in xrange(H):
        grid.append([0]*W)
    me_x, me_y = 0,0; x, y = 0,0
    for line in sz_grid.strip():
        char = line.strip().split()
        if char:
            if char[0] == 'X':
                me_x = x+0.5
                me_y = H-y-1+0.5
            grid[H-y-1][x] = char[0]
            x += 1
        else:
            x = 0
            y += 1
    #for g in grid[::-1]:
    #    print ''.join(g)
    #print 'origin =',grid[0][0]
    #print 'X@(%f,%f) %s' %(me_x,me_y,grid[int(floor(me_y))][int(floor(me_x))])

    #########################################################################
    # initialise ray #
    #########################################################################
    ray = {'delta': (.3,.4),
        'pos': Point(me_x,me_y),
        'dist': 0.0 }
    # scale ray to sqrt(2) length
    ray_mag = (ray['delta'][0]**2 + ray['delta'][1]**2)**0.5
    ray['delta'] = map(lambda x: sqrt(2)/ray_mag*x, ray['delta'])

    # move ray
    Q = Point(
        ray['pos'].x + ray['delta'][0],
        ray['pos'].y + ray['delta'][1]
    )
    #print 'new ray position=',Q

    old_grid_x = int(floor(ray['pos'].x))
    old_grid_y = int(floor(ray['pos'].y))
    reflect(old_grid_x,old_grid_y, ray, Q)

    # find new grid square where ray would be in
    new_grid_x = int(floor(Q.x))
    new_grid_y = int(floor(Q.y))
    #print new_grid_x,new_grid_y
    if 0 <= new_grid_x < W and 0 <= new_grid_y < H:
        #print 'new_grid_xy symbol =', grid[new_grid_y][new_grid_x]
        if grid[new_grid_y][new_grid_x] == '#':
            #print 'mirror! reflect...'
            reflect(new_grid_x,new_grid_y, ray, Q)
