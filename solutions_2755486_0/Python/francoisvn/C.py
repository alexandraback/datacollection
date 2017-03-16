#!/usr/bin/python

import sys

T = int(sys.stdin.readline())
for t in range(T):
  print >> sys.stderr, "Test: %d" % (t+1)
  toks = sys.stdin.readline().strip().split()
  N = int(toks[0])

  tribes = []
  for i in range(N):
    toks = sys.stdin.readline().strip().split()
    d = int(toks[0])
    n = int(toks[1])
    w = int(toks[2])
    e = int(toks[3])
    s = int(toks[4])
    dd = int(toks[5])
    dp = int(toks[6])
    ds = int(toks[7])
    tribes.append([d,n,w,e,s,dd,dp,ds,i])
  # print tribes

  W = 0
  E = 0
  for tribe in tribes:
    n = tribe[1]
    w0 = tribe[2]
    e0 = tribe[3]
    dp = tribe[6]
    wN = w0 + n*dp
    eN = e0 + n*dp
    W = min(W,w0,wN)
    E = max(E,e0,eN)
  # print W,E

  wall = [0]*(E-W+1)*2
  Z = -2*W # location of zero in array
  # print Z,wall

  day = 0
  A = 0
  while len(tribes) > 0:
    nwall = wall[:]
    for tribe in tribes:
      if day >= tribe[0]: # attack
        w = tribe[2]
        e = tribe[3]
        s = tribe[4]
        success = False
        for i in range(w*2,e*2+1):
          wi = Z+i
          if wall[wi] < s:
            success = True
            nwall[wi] = max(nwall[wi],s)

        # print wall,w,e,w*2+Z,e*2+Z
        # print "attack",tribe,success
        if success:
          A += 1
        tribe[0] += tribe[5]
        tribe[1] -= 1
        tribe[2] += tribe[6]
        tribe[3] += tribe[6]
        tribe[4] += tribe[7]
        if tribe[1] <= 0:
          tribes.remove(tribe)
    day += 1 # next day
    wall = nwall

  print "Case #%d: %d" % (t+1,A)

