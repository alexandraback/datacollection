import sys
import numpy
from cStringIO import StringIO


def doCase(E, R, varr):
  values = [0]*(E+1)  # start from 0 energy level; max E
  for v in varr:
    new_values = [0]*(E+1)
    for idx, val in enumerate(values):
      consumed = 0
      new_val = 0
      while consumed <= (E - idx):
	new_idx = max(0, consumed+idx-R)
	new_util = val + new_val
	new_values[new_idx] = max(new_util, new_values[new_idx])
	
	new_val += v
	consumed += 1


    values = new_values
  return max(values)



stdin = sys.stdin
num = stdin.readline()

#print num

for i in xrange(int(num)):
  E, R, N = stdin.readline().split(' ')  
  Varr = [int(x) for x in stdin.readline().split(' ')]
  assert(len(Varr) != N)
  val = doCase(int(E), int(R), Varr)
  sys.stdout.write( 'Case #%s: %s\n' % (i+1, val ))
