import sys
from decimal import *
getcontext().prec = 15


file = open(sys.argv[1])
T = int(file.readline())

def solve(s, N, Ji, s2):
  return max(((s + s2) / N - Ji)/s * 100, 0)

for X in range(T):
  data = map(Decimal, file.readline().strip().split(' '))
  N = data[0]
  J = data[1:]
  s = sum(J)
  results = []
  for i, Ji in enumerate(J):
    results.append(solve(s, N, Ji, s))
  s2 = 0
  for i, val in enumerate(results):
    if val == 0:
      N -= 1
    else:
      s2 += J[i]
  if min(results) == 0:
    for i, Ji in enumerate(J):
      if results[i] != 0:
        results[i] = solve(s, N, Ji, s2)
  #new_sum = sum(results)
  #if new_sum != 100:
  #  for i, Ji in enumerate(J):
  #    if (results[i] != 0):
  #      results[i] = results[i] * (Decimal(100) / new_sum)
  print 'Case #' + str(X + 1) + ': ' + ' '.join(map(str, results))
    
  