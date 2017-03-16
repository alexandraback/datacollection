# coding=utf-8

import os, sys, ljqpy, time
time.clock()

def Run(ss):
	f = ['']
	for k, v in enumerate(ss):
		z = f[k]
		nw = max([z + v, v + z])
		f.append(nw)
	return f[-1]

lst = ljqpy.LoadList('A-small-attempt0.in')
outf = 'A-small-attempt0.out'

with open(outf, 'w') as fout:
	for k, v in enumerate(lst[1:]):
		fout.write('Case #%d: %s\n' % (1+k,Run(v)))

os.system('emeditor.exe ' + outf)
print('completed')