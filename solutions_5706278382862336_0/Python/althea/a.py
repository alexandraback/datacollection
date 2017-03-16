import sys 
import string
from collections import *

def intersect(a, b):
	return list(set(a) & set(b))

f = open(sys.argv[1])
x = 2
powersof2 = {}
powersof2[0] = 0
for i in xrange(1, 41):
  powersof2[i] = x
  x = x*2
#print powersof2
T = int(f.readline())
for c in xrange(1, T+1): 
 line = f.readline().strip().split('/')
 n = int(line[0])
 d = int(line[1])
 answer = 0
 if (float(n)/float(d) > 0.5):
  n = n - (d*0.5)
  answer = 1
 elif d%2 != 0:
  answer = 'impossible'
 else:
  ct = 0
  while n>0:
    g = d
    tc = 0
    while g > n:
     g = g/2
     tc += 1
    if tc > ct:
     ct = tc
    n = n-g
  if n<0:
   answer = 'impossible'
  else: answer = ct

 print 'Case #' + str(c) + ': ' + str(answer)
	

