'''
Created on 05 May 2012

@author: dirk-b
'''

from collections import deque

inp = open('data/B-small-attempt0.in', 'r')
out = open('data/B-small-attempt0.out', 'w')

T = int(inp.readline())
for t in xrange(1, T + 1):
    H, N, M = map(int, inp.readline().split())
    roof = []
    floor = []
    
    roof.append([-1] * (M + 2))
    for i in xrange(N):
        x = [-1]
        x.extend(map(int, inp.readline().split()))
        x.append(-1)
        roof.append(x)
    roof.append([-1] * (M + 2))    
    
    floor.append([-1] * (M + 2))
    for i in xrange(N):
        x = [-1]
        x.extend(map(int, inp.readline().split()))
        x.append(-1)
        floor.append(x)
    floor.append([-1] * (M + 2))
    
    
    time = []
    for i in xrange(N + 2):
        time.append([float('inf')] * (M + 2))
    
    q = deque([])
    q.append(1)
    q.append(1)
    
    # drops at 10cm per second
    
    def mov(a, b, x, y):
        currwater = H - 10 * time[a][b]
        
        if ((floor[a][b] <= roof[x][y] - 50) and (floor[x][y] <= roof[x][y] - 50) and (floor[x][y] <= roof[a][b] - 50)):
            if currwater <= roof[x][y] - 50:
                # can move over water
                tTime = 1
                if floor[a][ b] > currwater - 20:
                    tTime = 10
                if time[a][b] == 0:
                    tTime = 0
                    
                if time[a][b] + tTime <= time[x][y] and time[x][y] != 0:
                    q.append(x)
                    q.append(y)
                    time[x][y] = time[a][b] + tTime 
            else:
                # have to wait for water to drop
                watertarget = roof[x][y] - 50
                tTime = (currwater - watertarget + 0.0) / 10
                if floor[a][b] > watertarget - 20:
                    tTime += 10
                else:
                    tTime += 1
                
                if time[a][b] + tTime <= time[x][y]:
                    q.append(x)
                    q.append(y)
                    time[x][y] = time[a][b] + tTime 
        
    time[1][1] = 0
    while len(q) > 0:
        x = q.popleft()
        y = q.popleft()
        
        #print x, y
        #print time
        #raw_input()
        
        mov(x, y, x + 1, y)
        mov(x, y, x, y + 1)
        mov(x, y, x - 1, y)
        mov(x, y, x, y - 1)
        
        # cant move if (currlevel <= nextroof - 50) && (nextfloor <= nextroof - 50) && (nextfloor <= currroof - 50)
        # time taken = 1 if currlevel - currfloor >= 20 else 10
        
        
    
    
    #print time
    #for x in time:
    #    print x
    #print
    #for x in floor:
    #    print x
    #print
    #for x in roof:
    #    print x
    #print
    #print    
    
    
    out.write("Case #%d: %.6f\n" % (t, time[-2][-2]))

inp.close()
out.close()
