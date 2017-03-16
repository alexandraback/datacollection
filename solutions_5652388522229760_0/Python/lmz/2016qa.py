import sys
import itertools
sys.setrecursionlimit(10000)

tc = int(sys.stdin.readline().strip())

for tmp_tc in xrange(tc):
  [ N ] = map(lambda x: int(x), sys.stdin.readline().strip().split(' '))
  ds = [ False ] * 10
  if N == 0:
    res = "INSOMNIA"
  else:
    res = N
    while True:
      for c in str(res):
        ds[int(c)] = True
      if sum(ds) == 10: break
      res += N
  print "Case #%d: %s" % (1+tmp_tc, str(res))

