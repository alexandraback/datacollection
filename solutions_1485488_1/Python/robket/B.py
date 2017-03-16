import heapq
moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]
for c in xrange(int(raw_input())):
  h, n, m = map(int, raw_input().split())
  ceil = []
  for i in xrange(n):
    ceil.append(map(int, raw_input().split()))
  floor = []
  for j in xrange(n):
    floor.append(map(int, raw_input().split()))
  ttb = [[-1]*m for i in xrange(n)]
  bq = [(0, 0)]
  q = [(0, (0, 0))]
  while (len(bq) != 0):
    curpos = bq[0]
    bq = bq[1:]
    #print "Queue:",bq
    #print "Curpos:",curpos
    if ttb[curpos[0]][curpos[1]] == 0: continue
    ttb[curpos[0]][curpos[1]] = 0
    heapq.heappush(q,(0, curpos))
    curfloor = floor[curpos[0]][curpos[1]]
    curceil = ceil[curpos[0]][curpos[1]]
    for i in moves:
      nextpos = (curpos[0] + i[0], curpos[1] + i[1])
      #print "Trying to get to", nextpos
      if nextpos[0] < 0 or nextpos[0] >= n or nextpos[1] < 0 or nextpos[1] >= m: continue
      nextfloor = floor[nextpos[0]][nextpos[1]]
      nextceil = ceil[nextpos[0]][nextpos[1]]
      if not ((nextceil - nextfloor >= 50) and (nextceil - curfloor >= 50) and (curceil - nextfloor >= 50) and (nextceil - h >= 50)): continue
      bq.append(nextpos)
      #print "Possible, Q:", bq
  #print "Q:", q
  while (len(q) != 0):
    cur = heapq.heappop(q)
    curpos = cur[1]
    if ttb[curpos[0]][curpos[1]] != -1 and ttb[curpos[0]][curpos[1]] < cur[0]: continue
    ttb[curpos[0]][curpos[1]] = cur[0]
    curfloor = floor[curpos[0]][curpos[1]]
    curceil = ceil[curpos[0]][curpos[1]]
    #print "Currently at", curpos
    for i in moves:
      nextpos = (curpos[0] + i[0], curpos[1] + i[1])
      if nextpos[0] < 0 or nextpos[0] >= n or nextpos[1] < 0 or nextpos[1] >= m: continue
      nextfloor = floor[nextpos[0]][nextpos[1]]
      nextceil = ceil[nextpos[0]][nextpos[1]]
      if not ((nextceil - nextfloor >= 50) and (nextceil - curfloor >= 50) and (curceil - nextfloor >= 50)): continue
      mintime = (h - (nextceil - 50)) / 10.0
      #print "valid to move to",nextpos ," leave at", mintime
      #print "only arrive at", cur[0]
      mintime = max(mintime, cur[0])
      if (h - (mintime * 10)) - curfloor >= 20:
        movetime = mintime + 1
        #print "enough water, toa:", movetime
      else:
        movetime = mintime + 10
        #print "have to dra, toa:", movetime
      heapq.heappush(q, (movetime, nextpos))
  print "Case #"+str(c+1)+": ", ttb[n-1][m-1]
