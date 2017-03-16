import sys
from decimal import *
getcontext().prec = 1000
i = 0

for line in sys.stdin:
 a, b = (int(s) for s in line.split())
 r = Decimal(a)
 t = Decimal(b)
 b = 2*r-1
 inn = b*b + 8*t
 res = -b + inn.sqrt()
 res = res/4;
 s = 'Case #%d: ' % (i+1)
 s += str(res.quantize(Decimal(1), rounding=ROUND_FLOOR))
 print s
 i = i + 1


