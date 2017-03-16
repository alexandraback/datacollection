#!/usr/bin/env python

import math
import random
import sys


N, J = map(int, sys.argv[1:])

def gen_mjc(N):
	return int('1' + ''.join(random.choice('01') for _ in range(N - 2)) + '1')

def is_jc(jc, t=10000):
	r = []
	for f in range(2, 10 + 1):
		ajc = int(str(jc), f)
		mm = int(ajc ** (1/10.0))
		#for _ in range(t * f * 5):
		for pd in range(3, mm):
			#pd = random.randint(3, mm + 1)
			if not (ajc % pd):
				r.append(pd)
				break
		else:
			#print >>sys.stderr, 'abort on base %d' % f
			return None
	return r

print 'Case #1:'

ojc = set()
while len(ojc) < J:
	jc = gen_mjc(N)
	r = is_jc(jc)
	if r and jc not in ojc:
		print '%d %s' % (jc, ' '.join(map(str, r)))
		ojc.add(jc)
