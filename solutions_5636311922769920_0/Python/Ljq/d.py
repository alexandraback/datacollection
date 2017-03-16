# coding=utf-8

import os, sys, ljqpy, time
time.clock()

def Run(v):
	k, c, s = map(int, v.split())
	ans = [(i+1)*k**(c-1) for i in range(k)]
	return ' '.join(str(x) for x in ans)

lst = ljqpy.LoadList('D-small-attempt0.in')
outf = 'D-small-attempt0.out'

with open(outf, 'w') as fout:
	for k, v in enumerate(lst[1:]):
		fout.write('Case #%d: %s\n' % (1+k,Run(v)))

os.system(outf)
print('completed')