#!/usr/bin/env python2
import numpy as np
for t in xrange(1,1+int(raw_input())):
	a,b,k=map(int,raw_input().split())
	A,B=np.mgrid[0:a,0:b]
	print"Case #%d:"%t,
	print((A&B)<k).sum()
