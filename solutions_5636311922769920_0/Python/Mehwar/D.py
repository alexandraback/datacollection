import sys
cin = sys.stdin.readline
def readints():
  return map(int, cin().split())
INF = sys.maxsize
NINF = -sys.maxsize - 1
#----------------------------------------------------------------------
# Dumb solution that uses a problem property to eek out a bm answr :)
T = int(cin())
for _t in xrange(T):
  K, C, S = readints()
  print "Case #{}: {}".format(_t + 1, ' '.join(map(str, range(1, S + 1))))
