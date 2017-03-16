import numpy as np

def solve(B, M, t):
  m = np.zeros((B, B), dtype=int)
  for i in xrange(B-1):
    for j in xrange(i+1, B):
      m[i][j] = 1
  
  L = 2**(B-2)
  if M > L:
    print "Case #%d: IMPOSSIBLE" % (t+1)
  else:
    remove = L - M
    while remove > 1:
      s = bin(remove)[2:]
      x = len(s) + s.find('1')
      m[x][B-1] = 0
      remove -= 2**(x-1)
    assert(remove <= 1)
    if remove == 1:
      m[0][B-1] = 0
    print "Case #%d: POSSIBLE" % (t+1)
    ans = ""
    for i in xrange(B):
      ans += "".join([str(x) for x in m[i]])
      if (i != B-1):
        ans += "\n"
    print ans

T = int(raw_input())
for i in xrange(T):
  B, M = [int(x) for x in raw_input().split()]
  solve(B, M, i)