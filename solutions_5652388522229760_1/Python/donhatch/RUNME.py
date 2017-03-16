#!/usr/bin/python

import sys

# Empirically, we can do N up to 1000000 using only 72 tries,
# so brain dead approach is fine.
def naive(N):
  if N == 0:
    return 'INSOMNIA',1
  verboseLevel = 0
  syndrome = [False] * 10
  for i in xrange(1000):
    iN = i*N
    scratch = iN
    while scratch > 0:
      syndrome[scratch%10] = True
      scratch //= 10
    if verboseLevel >= 1: print >>sys.stderr, "%s: %s %s" % (i, iN, ''.join([('1' if q else '0') for q in syndrome]))
    if syndrome == [True] * 10:
      return `iN`,i
  assert False

if len(sys.argv) >= 2:
  worst = 0
  for N in xrange(1, int(sys.argv[1])):
    answerNaive,iNaive = naive(N)
    print "Case #%s: %s (%s)" % (N, answerNaive, iNaive)
    worst = max(iNaive, worst)
  print "worst = "+`worst`
else:
  line = sys.stdin.readline().strip()
  nInputs = int(line)
  #print >>sys.stderr, "    nInputs = "+`nInputs`
  for iInput in xrange(nInputs):
    line = sys.stdin.readline().strip()
    #print >>sys.stderr, "        line = "+`line`
    N = int(line)
    answerNaive,iNaive = naive(N)
    print "Case #%s: %s" % (iInput+1, answerNaive)
