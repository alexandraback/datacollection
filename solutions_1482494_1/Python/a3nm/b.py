#!/usr/bin/python3

import sys
import operator
import heapq

T = int(sys.stdin.readline())


for i in range(T):
  by_1 = []
  by_2 = []
  done = []
  N = int(sys.stdin.readline())
  for j in range(N):
    l = sys.stdin.readline().rstrip().split(' ')
    by_1.append((j, int(l[0]), int(l[1])))
    by_2.append((j, int(l[1])))
    done.append(0)
  by_1.sort(key=lambda x: (x[1], -x[2]))
  by_2.sort(key=operator.itemgetter(1))
  stars = 0
  ndone = 0
  feasible1 = []
  while len(by_2) > 0:
    #print("ITERATION")
    #print stars
    #print ndone
    #print by_1
    #print(feasible1)
    #print by_2
    while (len(by_1) > 0 and by_1[0][1] <= stars):
      #print("BOB")
      pos, val, val2 = by_1.pop(0)
      heapq.heappush(feasible1, (-val2, pos))
      #print (feasible1)
      feasible1.sort()
      #print (feasible1)
    #print("POPULATED")
    #print(stars)
    #print(ndone)
    #print(by_1)
    #print(feasible1)
    #print(by_2)
    if ((len(feasible1) == 0)
        and (len(by_2) == 0 or by_2[0][1] > stars)):
      ndone = -1
      break
    if (len(feasible1) > 0 and done[feasible1[0][1]] >= 1):
      feasible1.pop(0)
      continue
    if (len(by_2) > 0 and done[by_2[0][0]] >= 2):
      by_2.pop(0)
      continue
    if (len(by_2) > 0 and by_2[0][1] <= stars):
      # we do a 2
      if done[by_2[0][0]] == 1:
        stars += 1
      else:
        stars += 2
      done[by_2[0][0]] = 2
      ndone += 1
      by_2.pop(0)
      continue
    if (len(feasible1) > 0):
      # we do a 1 because we can do no 2
      done[feasible1[0][1]] = 1
      ndone += 1
      stars += 1
      feasible1.pop(0)
      continue
    assert(False)
  if (ndone > 0):
    print("Case #%d: %d" % (i+1, ndone))
  else:
    print("Case #" + str(i+1)+ ": Too Bad")


