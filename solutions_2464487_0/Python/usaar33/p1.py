import sys
import numpy
from cStringIO import StringIO

def reeval(r,N):
  return 2*N*N+(2*r-1)*N

def doCase(r, t):
  array = [2,2*r-1,-t]
  q = numpy.roots(array)
  q = max(q)
  baseline = int(q)
  
  ev = 0
  
  # floating point pos
  while ev <= t:
    ev = reeval(r,baseline)
    baseline+=1
    
  return baseline-2

stdin = sys.stdin
num = stdin.readline()

#print num

for i in xrange(int(num)):
  N, M = stdin.readline().split(' ')  
  val = doCase(int(N), int(M))
  sys.stdout.write( 'Case #%s: %s\n' % (i+1, val ))
