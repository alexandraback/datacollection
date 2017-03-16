#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys, Queue

def BFS(X,Y):
    pere = {}
    dist = {}
    q = Queue.PriorityQueue()
    q.put((0,(0,0)))
    while q!=[]:
        (z,(x,y)) = q.get()
        if (x,y)==(X,Y):
            res = []
            cx,cy,cz = x,y,z
            while (cx,cy,cz)!=(0,0,0):
                nx,ny,nz = pere[(cx,cy,cz)]
                if nx-cx>0:
                    res.append('W')
                elif nx-cx<0:
                    res.append('E')
                elif ny-cy>0:
                    res.append('S')
                else:
                    res.append('N')
                cx,cy,cz = nx,ny,nz
            return ''.join(res[::-1])
        if not ((x,y,z) in dist):
            dist[(x,y,z)] = z
            if not ((x+z+1,y,z+1) in dist):
                q.put((z+1,(x+z+1,y)))
                pere[(x+z+1,y,z+1)] = (x,y,z)
            if not ((x-z-1,y,z+1) in dist):
                q.put((z+1,(x-z-1,y)))
                pere[(x-z-1,y,z+1)] = (x,y,z)
            if not ((x,y+z+1,z+1) in dist):
                q.put((z+1,(x,y+z+1)))
                pere[(x,y+z+1,z+1)] = (x,y,z)
            if not ((x,y-z-1,z+1) in dist):
                q.put((z+1,(x,y-z-1)))
                pere[(x,y-z-1,z+1)] = (x,y,z)

f = open(sys.argv[1],'r')
T = int(f.readline())
for t in range(1,T+1):
    l = map(int,f.readline().split())
    print 'Case #%d: %s' % (t,BFS(l[0],l[1]))
