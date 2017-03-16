# -*- coding: utf-8 -*-
"""
@author: Ivan Koblik
"""

import sys, heapq

if len(sys.argv) <= 1:
    print "Expected input file name"
    exit(0)

def read_cases(from_file):
    with open(from_file) as f:
        lines = f.readlines()
    num_samples = int(lines[0])
    result = []
    current_row = 1
    for i in range(num_samples):
        x,y = map(int, lines[current_row].split(" "))
        result.append((x,y))        
        current_row += 1
    return result

E = "E"
W = "W"
N = "N"
S = "S"

"""Heuristic function"""
def h(n, x0, y0, x, y):
    hor = nhor = x0 < x
    ver = nver = y0 < y

    cc = 0    
    step = n
    while ((hor == nhor and x0 != x) or (ver == nver and y0 != y)):
        if (hor == nhor):
            x0 = x0 + (1 if hor else -1) * step
            nhor = x0 < x
        else:
            y0 = y0 + (1 if ver else -1) * step
            nver = y0 < y
        step = step + 1
        cc += 1
    return cc

def fringe(n,x,y):
    return [(x+n,y,n+1,E), (x-n, y, n+1,W), (x, y+n,n+1,N), (x,y-n,n+1,S)]

def astar(x,y):
    backtrack = {}
    walked = set() #set of walked nodes in the state graph
    heap = [(0, 0, (0,0,1,""), None)] #g+h, g, (x,y,n,dir)
    while (len(heap) != 0):
        _,g,node,parent = heapq.heappop(heap)
        x0,y0,n0,D0 = node
        if ((x0,y0,n0) in walked):
            continue
        walked.add((x0,y0,n0))
        backtrack[(x0,y0,n0)] = parent
        if x0 == x and y0 == y:
            res = [D0]
            while (parent is not None):
                res.insert(0, parent[3])
                #print parent
                parent = backtrack[parent[:3]]
            return res[1:]
        fr = fringe(n0, x0, y0)
        refback = (x0,y0,n0,D0)
        for x1,y1,n1,d1 in fr:
            heuristic = h(n1,x1,y1,x,y)
            heapq.heappush(heap, (heuristic+g+1,g+1,(x1,y1,n1,d1), refback))
    return []
        

coords = read_cases(sys.argv[1])
for i in range(len(coords)):
    x,y = coords[i]
    print "Case #" + str(i+1) + ": " + "".join(astar(x,y))
