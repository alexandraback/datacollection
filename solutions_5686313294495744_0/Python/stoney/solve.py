INPUT_FILE = "in.txt"

entries = []

def getDD(X, Xdo, Y, Ydo, N, z):
  Xd = dict(Xdo)
  Yd = dict(Ydo)
  cnt = 0
  for j in xrange(N):
    if ((1<<j) & z) != 0:
      cnt += 1
      if Xd[X[j]] < 2 or Yd[Y[j]] < 2:
        return None
      Xd[X[j]] -= 1
      Yd[Y[j]] -= 1
  return cnt

with open(INPUT_FILE, 'r') as fin:
  T = int(fin.readline())
  for i in xrange(1, T+1):
    N = int(fin.readline())
    X = []
    Y = []
    Xd = dict()
    Yd = dict()
    for n in xrange(N):
      line = fin.readline().split()
      X += [line[0]]
      if line[0] in Xd:
        Xd[line[0]] += 1
      else:
        Xd[line[0]] = 1
      Y += [line[1]]
      if line[1] in Yd:
        Yd[line[1]] += 1
      else:
        Yd[line[1]] = 1

    maxr = 0
    for z in xrange(1, 1 << N):
      r = getDD(X, Xd, Y, Yd, N, z)
      if r != None and r > maxr:
        maxr = r
    print "case #%d: %d" % (i, maxr)
