import sys
import itertools
sys.setrecursionlimit(10000)

tc = int(sys.stdin.readline().strip())

for tmp_tc in xrange(tc):
  [ N ] = map(lambda x: int(x), sys.stdin.readline().strip().split(' '))
  ws = []
  for _n in xrange(N):
    ws.append(sys.stdin.readline().strip().split(' '))

  cache = {}
  def dp(cfg):
    if cfg == 0: return 0
    if cfg in cache: return cache[cfg]
    res = 0
    for n in xrange(N):
      cfg_n = 1 << n
      if cfg & cfg_n:
        fake_left, fake_right = False, False
        for m in xrange(N):
          if n == m: continue
          if cfg & (1 << m):
            if ws[n][0] == ws[m][0]: fake_left = True
            if ws[n][1] == ws[m][1]: fake_right = True
        tmp = dp(cfg - cfg_n)
        if fake_left and fake_right: tmp += 1
        res = max(res, tmp)
    cache[cfg] = res
    return res

  res = dp((1 << N) - 1)
  print "Case #%d: %d" % (1+tmp_tc, res)

