import sys
import string

def solveWar(first, second, n):  
  res = 0
  firstIt = 0
  secondIt = 0
  while secondIt < n:
    if first[firstIt] < second[secondIt]:
      res = res + 1
      firstIt = firstIt + 1
      secondIt = secondIt + 1
    else:
      secondIt = secondIt + 1
  
  return res


numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
  n = int(sys.stdin.readline())

  params = string.split(sys.stdin.readline().strip())
  naomis = sorted([float(i) for i in params])

  params = string.split(sys.stdin.readline().strip())
  kens = sorted([float(i) for i in params])

  print 'Case #' + repr(casenum) + ': ' + repr(solveWar(kens, naomis, n)) + ' ' + repr(n - solveWar(naomis, kens, n))
