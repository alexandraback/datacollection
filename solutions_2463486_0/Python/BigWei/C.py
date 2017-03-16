import sys
import numpy as np
from math import *
T = int(raw_input());
def palin(a):
	a = str(a);
	a == a[::-1]
	return a == a[::-1]

def go(s , d):
	return table[0][floor(sqrt(d))] - table[0][ceil(sqrt(s)) - 1];
table= np.zeros((1 , 1e7 +5));
for i in xrange(1 , int(1e7 + 2)):
  table[0][i] = table[0][i-1]
  if palin(int(pow(i , 2))) == True and palin( i) ==True:
	table[0][i]+=1;
for C in xrange(T):
  a , b = raw_input().split()
  a = int(a)
  b = int(b);
  print 'Case #%d: %d' %(C+1 , go(a,b))
