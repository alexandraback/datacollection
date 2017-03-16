import math
from decimal import *

getcontext().prec = 1000

# math.pi

f = file('A-large.in')

cases = int(f.readline())

def area(r):
  return ((r+1)**2 - r**2)

def solve(r, t):
  total = 0
  while True:
    t = t - area(r)
    if t < 0:
      break
    total += 1
    r += 2
  return total

def solve2(r, t):
  a1 = Decimal(r*2 + 1)
  sq = Decimal(Decimal.sqrt((2 * a1 - 4)**2 + 32 * t))
  return int(math.floor((-(2 * a1 -4) + sq) / 8))

  # first one needs r*2 + 1
  # each one needs 4 more.
  # so atithmeti series with d = 4 and a1 = r*2 + 1
  # The Sum =


for i in range(1, cases + 1):
  r, t = map(Decimal, list(f.readline().split()))
  sol = solve2(r, t)
  print 'Case #' + str(i) + ': ' + str(sol)

