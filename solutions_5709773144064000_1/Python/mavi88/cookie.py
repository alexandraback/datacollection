from math import *
import numpy as np

T = int(raw_input())

for t in range(T):
	C,F,X = map(float, raw_input().strip().split())
	k = max(0,int(ceil((X-C)/C - 2.0/F)))
	a = [C/(i*F+2.0) for i in range(k)]
	s = sum(np.cumsum(a))
	res = (X+F*s+k*C)/(k*F+2.0)
	res = round(res,6)
	print "Case #" + str(t+1) + ": " + str(res)