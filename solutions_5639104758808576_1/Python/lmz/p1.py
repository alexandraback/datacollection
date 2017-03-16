import sys

tc = int(sys.stdin.readline())
for tmp_tc in xrange(tc):
  [ smax, ss ] = sys.stdin.readline().rstrip('\n').split(' ')
  res = 0
  total = 0
  smax = int(smax)
  for i in xrange(smax+1):
    s = int(ss[i])
    if total < i:
      res += i - total
      total = i
    total += s
  print "Case #%d: %d" % (tmp_tc + 1, res)
