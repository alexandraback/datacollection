# coding=utf-8

import os, sys, ljqpy, time
import numpy as np
time.clock()

def Run(n, inp):
	ns = {}
	for vv in inp:
		for v in vv: 
			ns[v] = ns.get(v, 0) + 1
	rs = [x for x,y in ns.items() if y % 2 == 1]
	rs.sort()
	return ' '.join(map(str, rs))

lst = ljqpy.LoadList('B-large.in')
outf = 'B-large.out'

with open(outf, 'w') as fout:
	ii = 0
	T = int(lst[ii])
	ii += 1
	for k in range(T):
		n = int(lst[ii])
		ii += 1
		inp = []
		for j in range(2*n-1):
			inp.append(tuple(map(int, lst[ii].split())))
			ii += 1
		inp.sort()
		fout.write('Case #%d: %s\n' % (1+k,Run(n, inp)))

os.system('emeditor.exe ' + outf)
print('completed')