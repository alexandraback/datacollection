import math

f = open('B-small-attempt0.in', 'r')
T = int(f.readline())
for testCase in range(1, T+1):
  D = int(f.readline())
  P = map(int, f.readline().split())

  currentBest = float("inf")
  
  for targetP in range(1, max(P)+1): 
    extraMins = 0

    for i in range(D):
      extraMins += math.ceil(float(P[i]) / float(targetP)) - 1
    totalTime = extraMins + targetP
    if (currentBest > totalTime):
      currentBest = totalTime


  print "Case #%d: %d" % (testCase, currentBest)