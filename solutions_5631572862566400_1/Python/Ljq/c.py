# coding=utf-8

import os, sys, ljqpy, time
time.clock()

def Run(n, inp):
	rt = 0
	inp = [x-1 for x in inp]
	exe, mask = [0] * n, 0
	for i in range(n):
		if exe[i] != 0: continue
		mask += 1
		z = i
		ls = []
		while exe[z] == 0:
			exe[z] = mask
			ls.append(z)
			z = inp[z]
		if z in ls:
			rt = max( [rt, (len(ls)-ls.index(z))] )
	ls = []
	for i in range(n):
		if inp[inp[i]] == i:
			ls.append(i)
	exe = [-1] * n
	for v in ls: exe[v] = 0

	edge = {}
	for i in range(n):
		edge.setdefault(inp[i], []).append(i)

	def FindL(v):
		q = [v]
		mm = exe.copy()
		qh = 0
		while qh < len(q):
			z = q[qh]
			qh += 1
			for i in edge.get(z, []):
				if mm[i] != -1: continue
				mm[i] = mm[z] + 1
				q.append(i)
		return max(mm)

	#print(ls)
	rr = len(ls)
	for v in ls:
		rr += FindL(v)
	return max([rt, rr])

lst = ljqpy.LoadList('C-large.in')
outf = 'C-large.out'

with open(outf, 'w') as fout:
	ii = 0
	T = int(lst[ii])
	ii += 1
	for k in range(T):
		n = int(lst[ii])
		ii += 1
		inp = tuple(map(int, lst[ii].split()))
		ii += 1
		fout.write('Case #%d: %d\n' % (1+k,Run(n, inp)))

os.system('emeditor.exe ' + outf)
print('completed')