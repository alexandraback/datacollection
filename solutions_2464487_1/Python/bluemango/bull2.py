
from mpmath import *
mp.dps = 200
mp.pretty = True

f=open('inputlarge.txt')

def solve(r, t):
  b = (r * 2) - 1

  n = int((-b + sqrt(b*b + (8*t))) / 4)
  return n

numInputs = int(f.readline())


for i,line in enumerate(f):
  args = line.split(' ')
  r = int(args[0])
  t = int(args[1])

  # print r,t
  print 'Case #{0}: {1} '.format(i+1, solve(r, t))

