#!/bin/python
from math import *

T = int(raw_input())
for t in range(1, T+1):
	print "Case #"+str(t)+":", 
	In = raw_input().split()
	r = int(In[0])
	t = int(In[1])

	a = 2
	b = 2*r-1
	c = -1 * t

	root = ((-1*b) + sqrt(b*b-4*a*c))/(2*a)

	print int(root)
