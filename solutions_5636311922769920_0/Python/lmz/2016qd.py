import sys
import itertools
sys.setrecursionlimit(10000)

tc = int(sys.stdin.readline().strip())

for tmp_tc in xrange(tc):
  [ K, C, S ] = map(lambda x: int(x), sys.stdin.readline().strip().split(' '))
  res = "IMPOSSIBLE"
  idxs = []
  for k in xrange(0, K, C):
    # test positions k to k+C-1
    idx = 0
    for kk in xrange(k, min(K, k+C)):
      idx = K * idx + kk
    idxs.append(idx)
  if len(idxs) <= S:
    res = ' '.join([str(i+1) for i in idxs])
  print "Case #%d: %s" % (1+tmp_tc, res)

