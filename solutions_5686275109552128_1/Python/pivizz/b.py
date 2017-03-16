import sys
from heapq import *

def solve(case):
  h = []
  res = max(case)
  for p in case:
    heappush(h, (-p, 1, p))
  
  i = 1
  while i < res:
    a,b,c = heappop(h)
    b += 1
    a = -((c+b-1)//b)
    heappush(h, (a,b,c))
    nres = -h[0][0] + i
    if nres < res:
      res = nres
    i += 1

  return res

data = list(sys.stdin)[1:]
ncases = len(data) // 2

for caseIndex in range(ncases):
  case = list(map(int, data[2*caseIndex+1].rstrip().split(' ')))
  answer = solve(case)
  print('Case #{0}: {1}'.format(caseIndex+1, answer))


