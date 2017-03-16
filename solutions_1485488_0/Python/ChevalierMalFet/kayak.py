import heapq
from copy import *

def successors(floor, roof, loc):
    x = loc[0]
    y = loc[1]
    n = len(floor)
    m = len(floor[0])
    succ = []
    if (x > 0 and roof[x-1][y] - floor[x-1][y] >= 50
              and roof[x-1][y] - floor[x][y] >= 50
              and roof[x][y] - floor[x-1][y] >= 50):
        succ += [(x-1,y)]
    if (x < n-1 and roof[x+1][y] - floor[x+1][y] >= 50
              and roof[x+1][y] - floor[x][y] >= 50
              and roof[x][y] - floor[x+1][y] >= 50):
        succ += [(x+1,y)]
    if (y > 0 and roof[x][y-1] - floor[x][y-1] >= 50
              and roof[x][y-1] - floor[x][y] >= 50
              and roof[x][y] - floor[x][y-1] >= 50):
        succ += [(x,y-1)]
    if (y < m-1 and roof[x][y+1] - floor[x][y+1] >= 50
              and roof[x][y+1] - floor[x][y] >= 50
              and roof[x][y] - floor[x][y+1] >= 50):
        succ += [(x,y+1)]
    return succ

def cost(loc, nextLoc, floor, roof, w):
    waterLevel = deepcopy(w)
    x = loc[0]
    y = loc[1]
    xn = nextLoc[0]
    yn = nextLoc[1]
    t = 0.0
    if roof[xn][yn] - waterLevel < 50:
        t += (waterLevel - (roof[xn][yn]-50)) / 10.0
        waterLevel = roof[xn][yn]-50
    if waterLevel-20 < floor[x][y]:
        return t+10
    else:
        return t+1

def dijkstra(roof, floor, s, t, waterLevel):
    ''' Return predecessors and min distance if there exists a shortest path 
        from s to t; Otherwise, return None '''
    Q = []     # priority queue of items; note item is mutable.
    d = {s: 0} # vertex -> minimal distance
    Qd = {}    # vertex -> [d[v], parent_v, v]
    p = {}     # predecessor
    visited_set = set([s])
    if s == t:
        return 0.0
    for v in successors(floor, roof, s):
        d[v] = cost(s, v, floor, roof, waterLevel)
        item = [d[v], s, v]
        heapq.heappush(Q, item)
        Qd[v] = item

    while Q:
        #print Q
        c, parent, u = heapq.heappop(Q)
        if u not in visited_set:
            #print 'visit:', u
            p[u]= parent
            visited_set.add(u)
            if u == t:
                return d[u]
            for v in successors(floor, roof, u):
                if d.get(v):
                    if d[v] > cost(s, v, floor, roof, waterLevel-(d[u]*10)) + d[u]:
                        d[v] =  cost(s, v, floor, roof, waterLevel-(d[u]*10)) + d[u]
                        Qd[v][0] = d[v]    # decrease key
                        Qd[v][1] = u       # update predecessor
                        heapq._siftdown(Q, 0, Q.index(Qd[v]))
                else:
                    d[v] = cost(s, v, floor, roof, waterLevel-(d[u]*10)) + d[u]
                    item = [d[v], u, v]
                    heapq.heappush(Q, item)
                    Qd[v] = item

    return None

def getStartingLocs(f, roof, waterLevel):
    floor = deepcopy(f)
    for i in range(len(floor)):
        for j in range(len(floor[0])):
            if floor[i][j] < waterLevel:
                floor[i][j] = max(waterLevel, floor[i][j])
    s = []
    toExpand = [(0,0)]
    while toExpand != []:
        a = toExpand.pop()
        s += [a]
        succ = successors(floor, roof, a)
        for c in succ:
            if c not in s and c not in toExpand:
                toExpand += [c]
    return s

inputFile = open("B-small-attempt3.in", 'r')
outputFile = open("kayakOutSmall3.txt", 'w')
numTests = int(inputFile.readline())


for i in range(numTests):
    line = inputFile.readline().split()
    waterLevel = int(line[0])
    n = int(line[1])
    m = int(line[2])
    roof = []
    for j in range(n):
        line = inputFile.readline().split()
        for k in range(m):
            line[k] = int(line[k])
        roof += [line]
    floor = []
    for j in range(n):
        line = inputFile.readline().split()
        for k in range(m):
            line[k] = int(line[k])
        floor += [line]
    startingLocs = getStartingLocs(floor, roof, waterLevel)
    bestCost = 10000000
    for k in range(len(startingLocs)):
        x = dijkstra(roof, floor, startingLocs[k], (n-1,m-1), waterLevel)
        if x != None and x < bestCost:
            bestCost = x
    outputFile.write('Case #' + str(i+1) + ': ' + str(bestCost*1.0) + '\n')


inputFile.close()
outputFile.close()
