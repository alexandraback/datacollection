import sys
import itertools
sys.setrecursionlimit(10000)

tc = int(sys.stdin.readline().strip())

def matches(C):
  l = len(C)
  min_c = 1
  for i in xrange(l-1): min_c *= 10
  valid_c = []
  for c in xrange(10*min_c):
    sc = str(c).zfill(l)
    ok = True
    for i, x in enumerate(C):
      if x != '?' and x != sc[i]:
        ok = False
        break
    if ok: valid_c.append(c)
  return valid_c


for tmp_tc in xrange(tc):
  [ C, J ] = sys.stdin.readline().strip().split(' ')
  valid_c = matches(C)
  valid_j = matches(J)
  current_min, where_min = None, None
  for c in valid_c:
    for j in valid_j:
      d = abs(c-j)
      if current_min is None or d < current_min:
        current_min = d
        where_min = c, j
  l = len(C)
  c, j = where_min
  print "Case #%d: %s %s" % (1+tmp_tc, str(c).zfill(l), str(j).zfill(l))
