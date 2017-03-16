from collections import defaultdict
import random

cases = int(raw_input())

t = 1
while True:
  print 'Case #%d:' % t,
  t += 1

  j, p, s, k = [ int(x) for x in raw_input().split() ]

  jjpp = defaultdict(lambda : 0)
  ppss = defaultdict(lambda : 0)
  jjss = defaultdict(lambda : 0)
  soln = []
  for jj in xrange(1, j+1):
    for pp in xrange(1, p+1):
      for ss in xrange(1, s+1): 
        if (jjpp[(jj, pp)] < k):
          if (ppss[(pp, ss)] < k):
            if (jjss[(jj, ss)] < k):
              jjpp[(jj, pp)] += 1
              ppss[(pp, ss)] += 1
              jjss[(jj, ss)] += 1
              soln.append([jj, pp, ss])

  print len(soln)
  for sol in soln:
    print ' '.join([str(x) for x in sol])

  if t == cases + 1:
    break
