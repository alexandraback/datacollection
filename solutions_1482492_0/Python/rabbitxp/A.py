#!/usr/bin/env python

import math

_FMT_ = 'Case #%d:\n'
f = open('in','r')
_T_ = int(f.readline())
g = open('out','w')

for _t_ in xrange(_T_): 

	#INPUT
	tokens  = f.readline().strip().split()

	#TODO ----------------------------------------------
	D = float(tokens[0])
	N = int(tokens[1])
	A = int(tokens[2])

	T = []
	Y = []
	MINA = []
	for n in xrange(N):
		t, y = [float(x) for x in f.readline().strip().split()]
		if y > D:
			if n==0: 
				for n in xrange(N-1): f.readline()
				break
			v = 1.0*(y-0.5*Y[n-1])/(t-T[n-1])
			y = D
			t = T[n-1] + 1.0*(D-0.5*Y[n-1])/v
			T.append(t)
			Y.append(2.0*y)
			MINA.append(2.0*y/(t*t))
			for n in xrange(N-1-n): f.readline()
		T.append(t)
		Y.append(2.0*y)
		if n>0: MINA.append(2.0*y/(t*t))
		else: MINA.append(0.0)
	AA = [float(x) for x in f.readline().strip().split()]

	#OUTPUT
	g.write(_FMT_ %(_t_+1))

	for a in AA:
		dt_max = 0.0
		for n in xrange(1,len(MINA)):
			if a < MINA[n]: continue
			dt = T[n] - math.sqrt(Y[n]/a)
			if dt > dt_max: dt_max = dt
		dt_max += math.sqrt(2.0*D/a)
		g.write(str(dt_max)+'\n')
		print dt_max

