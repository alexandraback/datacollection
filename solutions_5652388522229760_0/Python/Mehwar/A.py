import sys
cin = sys.stdin.readline
def readlist():
  return map(int, cin().split())
INF = sys.maxsize
NINF = -sys.maxsize - 1
#----------------------------------------------------------------------
from collections import defaultdict, Counter
import operator

T = int(cin())
for _t in xrange(T):
  N = int(cin())
  seen = set()
  last = -1
  for i in xrange(1, 1000):
    num = N * i
    seen |= set(str(num))
    if len(seen) == 10:
      last = num
      break

  print "Case #{}: {}".format(_t + 1, last if last != -1 else 'INSOMNIA')
