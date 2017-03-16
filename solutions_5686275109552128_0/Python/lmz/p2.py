import sys

cache = {}
def walk(ps):
  ps = list(sorted(ps))
  if max(ps) == 0: return 0
  if max(ps) == 1: return 1
  if max(ps) == 2: return 2
  key = tuple(ps)
  if key in cache: return cache[key]
  pmax = 0
  for i, p in enumerate(ps):
    if pmax < p:
      pmax = p
      wheremax = i
  res = walk(map(lambda x : max(x - 1, 0), ps))
  for p in xrange(1, pmax):
    ps = list(key)
    ps[wheremax] = p
    ps.append(pmax - p)
    res = min(res, walk(ps))
  res += 1
  cache[key] = res
  return res

tc = int(sys.stdin.readline())
for tmp_tc in xrange(tc):
  [ D ] = map(lambda x: int(x), sys.stdin.readline().rstrip('\n').split(' '))
  ps = map(lambda x: int(x), sys.stdin.readline().rstrip('\n').split(' '))
  print "Case #%d: %d" % (tmp_tc + 1, walk(tuple(ps)))
