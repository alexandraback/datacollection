import sys
import string

def accumulate(lis):
    total = 0.0
    for x in lis:
        total += x
        yield total

def solve(C, F, X):
  
  INIT_CPS = 2.0
  waitTimeForIthFarm = [0.0] + [C/(INIT_CPS + F*i) for i in range(int(X)+3)]
  waitTimeForIthFarmAccumulated = list(accumulate(waitTimeForIthFarm))

  bestResult = X/INIT_CPS
  for farmsCount, totalWaitTimeForFarms in enumerate(waitTimeForIthFarmAccumulated):
    cand = totalWaitTimeForFarms + X/(INIT_CPS + F*farmsCount)
    bestResult = min(bestResult, cand)
   
  return bestResult

def printFloat(floatNumber):
  return "{0:.7f}".format(floatNumber)

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
  params = string.split(sys.stdin.readline().strip())
  C = float(params[0])
  F = float(params[1])
  X = float(params[2])

  print 'Case #' + repr(casenum) + ': ' + printFloat(solve(C, F, X))
