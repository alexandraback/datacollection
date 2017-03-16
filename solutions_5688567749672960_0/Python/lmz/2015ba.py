import sys

tc = int(sys.stdin.readline())
maxN = 10**6
bests = [ None ] * (maxN + 1)
bests[1] = 1
for N in xrange(2, maxN+1):
  strN = str(N)
  revN = int(''.join(reversed(strN)))
  if revN < N and strN[-1] != '0':
    bests[N] = min(bests[N-1], bests[revN]) + 1
  else:
    bests[N] = bests[N-1] + 1

for tmp_tc in xrange(tc):
  [ N ] = map(lambda x: int(x), sys.stdin.readline().split(' '))
  print "Case #%d: %d" % (1+tmp_tc, bests[N])
