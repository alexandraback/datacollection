#!/usr/bin/python
import sys
from operator import itemgetter

def calc(Y):
  X = float(sum(Y))
  ret = [0.0] * len(Y)
  Yfixed = sorted(enumerate(Y), key=itemgetter(1))
  for i in xrange(len(Yfixed)):
    smaller_sum = sum([p[1] for p in Yfixed[:i]])
    if i > 0 and (smaller_sum + X)/i <= Yfixed[i][1]:
      ret[Yfixed[i][0]] = 0.0
      continue
    sss = smaller_sum + X + Yfixed[i][1]
    j = i
    while j < len(Yfixed)-1 and (sss / (j+1)) > Yfixed[j+1][1]:
      sss += Yfixed[j+1][1]
      j += 1
    ret[Yfixed[i][0]] = 100.0*((sss/(j+1)) - Yfixed[i][1])/X
      
  return " ".join([str(k) for k in ret])

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  for j in xrange(1, n+1):
    s = [int(x) for x in d[j].split(' ')]
    print "Case #%d: %s" % (j, calc(s[1:]))
main()
