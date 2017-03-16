import sys
import string
inp = sys.stdin
T = int(inp.readline())

for cas in xrange(1, T + 1):
  print "Case #%d:" % cas
  ints = [int(x) for x in inp.readline().split(' ')]
  N = ints.pop(0)
  assert N == len(ints)
  def pr(x):
    for j in xrange(N):
      if x & (1 << j):
        print ints[j],
    print
  sums = {}
  for i in xrange(1, 1 << N):
    s = 0
    for j in xrange(N):
      if i & (1 << j):
        s += ints[j]
    if s not in sums:
      sums[s] = [i]
    else:
      for x in sums[s]:
        if (i & x) == 0:
          pr(x)
          pr(i)
          break
      else:
        sums[s].append(i)
        continue
      break
  else:
    print 'Impossible'
