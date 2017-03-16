import sys
def cin():
  return sys.stdin.readline().strip()
def readlist():
  return map(int, cin().split())
INF = sys.maxsize
NINF = -sys.maxsize - 1
#----------------------------------------------------------------------

def conv(plusorminus):
  return 1 if plusorminus == '+' else -1

T = int(cin())
for _t in xrange(T):
  S = map(conv, list(cin()))
  ans = 0
  trail = len(S) - 1
  while trail >= 0:
    if S[trail] == -1:
      for i in xrange(0, trail + 1):
        S[i] = -1 * S[i]
      ans += 1
    trail -= 1

  print "Case #{}: {}".format(_t + 1, ans)

