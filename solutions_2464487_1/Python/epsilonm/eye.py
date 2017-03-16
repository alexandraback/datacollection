import math
from decimal import *
getcontext().prec = 200
cases = int(raw_input())
defaultround=getcontext().rounding
def do(r, t):
  getcontext().rounding=defaultround
  a=  Decimal(1)+Decimal(.25)*(Decimal(4*r*r-4*r+8*t+1).sqrt() - Decimal(2*r+3))

  getcontext().rounding=ROUND_FLOOR
  return int(a)

for case in xrange(1,cases+1):
  r, t = map(int, raw_input().split(' '))

  ans = do(r,t)


  print 'Case #%d: %s' % (case, str(ans))