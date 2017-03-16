import sys
cin = sys.stdin.readline
def readints():
  return map(int, cin().split())
INF = sys.maxsize
NINF = -sys.maxsize - 1
#----------------------------------------------------------------------
from random import shuffle
from copy import deepcopy
MAX_REPEAT = 10000


T = int(cin())
for _t in xrange(T):
  J, P, S, K = readints()
  combos = []
  bestcombos = []
  for mr in xrange(MAX_REPEAT):
    jp = [[0] * 10 for _ in xrange(10)]
    js = [[0] * 10 for _ in xrange(10)]
    ps = [[0] * 10 for _ in xrange(10)]
    for j in range(J):
      pp = range(P)
      shuffle(pp)
      for p in pp:
        ss = range(S)
        shuffle(ss)
        for s in ss:
          if jp[j][p] == K or js[j][s] == K or ps[p][s] == K:
            continue
          jp[j][p] += 1
          js[j][s] += 1
          ps[p][s] += 1
          combos.append(' '.join([str(_) for _ in [j + 1, p + 1, s + 1]]))

    if len(combos) >= len(bestcombos):
      bestcombos = deepcopy(combos)
    combos = []


  print "Case #{}: {}".format(_t + 1, len(bestcombos))
  print '\n'.join(bestcombos)
