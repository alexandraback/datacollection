import sys
def cin():
  return sys.stdin.readline().strip()
def readints():
  return map(int, cin().split())
INF = sys.maxsize
NINF = -sys.maxsize - 1
#----------------------------------------------------------------------

def cc(i):
  return chr(i + 48)

T = int(cin())
for _t in xrange(T):
  B, M = readints()
  maximum = 2 ** (B - 2)
  if M > maximum:
    print "Case #{}: IMPOSSIBLE".format(_t + 1)
    continue

  matrix = [[0] * B for b in xrange(B)]
  for i in xrange(B - 1):
    matrix[i][B - 1] = 1  # Connect everything to B

  curr = 1
  nxt = 0
  plus = 1
  while curr < M:
    for i in xrange(nxt + 1, B - 1):
      curr += plus
      matrix[nxt][i] = 1
      if curr >= M:
        break
    nxt += 1
    plus = 2 ** (nxt - 1)

  diff = curr - M
  powers = [2 ** i for i in xrange(55)]
  while diff > 0:
    pindex = 0
    for i in xrange(len(powers)):
      if powers[i] > diff:
        pindex = i - 1
        break
    nxt = pindex + 1
    matrix[nxt][B - 1] = 0
    diff -= powers[pindex]


  print "Case #{}: POSSIBLE".format(_t + 1)
  print '\n'.join([''.join([str(_) for _ in mm]) for mm in matrix])
