from heapq import heappush, heappop
from collections import deque
T = int(raw_input())

for case in xrange(T):
    H,N,M = map(int, raw_input().split())
    ceiling = [ [x for x in map(int,raw_input().split()) ]  for x in xrange(N) ]
    floor = [ [x for x in map(int,raw_input().split()) ]  for x in xrange(N) ]
    visited = [ [False]*M  for x in xrange(N) ]
    visited[0][0] = True
    que = deque([(0,0)])
    dque =  [  ]
    heappush(dque,(0.0,0,0))
    #find starting points
    while len(que) > 0:
        y, x = que.popleft()
        for dx,dy in ((1,0),(0,1),(-1,0),(0,-1)):
            px = x + dx
            py = y + dy
            if px < 0 or px >= M or py < 0 or py >= N:
                continue
            if ceiling[py][px] - floor[py][px] < 50 or \
                ceiling[py][px] - floor[y][x] < 50 or \
                ceiling[y][x] - floor[py][px] < 50:
                continue
            if ceiling[py][px] - H >= 50 and ( visited[py][px] == False ):
                que.append((py,px))
                heappush(dque,(0.0,py,px))
                visited[y][x] = True
    score= [ [-1]*M  for x in xrange(N) ]
    while len(dque) > 0:
        cw, y, x = heappop(dque)
        if score[y][x] != -1:
            continue
        score[y][x] = cw
        W = H - 10*cw
        for dx,dy in ((1,0),(0,1),(-1,0),(0,-1)):
            px = x + dx
            py = y + dy
            if px < 0 or px >= M or py < 0 or py >= N:
                continue
            if ceiling[py][px] - floor[py][px] < 50 or \
                ceiling[py][px] - floor[y][x] < 50 or \
                ceiling[y][x] - floor[py][px] < 50:
                continue
            #Go as soon as you get there
            if ceiling[py][px] - W  >= 50:
                if W - floor[y][x] < 20:
                    heappush(dque,(cw + 10.0,py,px))

                else:
                    heappush(dque,(cw + 1.0,py,px))
            else:
                wait = (W - (ceiling[py][px] - 50))/10.0
                if W -wait*10.0 - floor[y][x] < 20:
                    heappush(dque,(cw + wait + 10.0,py,px))
                else:
                    heappush(dque,(cw + wait + 1.0,py,px))
    print "Case #%d: %.6f" % (case+1,score[N-1][M-1])















