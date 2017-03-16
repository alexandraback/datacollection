#!/usr/bin/python
import sys
f = open('b.in')
T = int(f.readline())
for i in range(T):
	N = int(f.readline())
	mark = {}
	for j in range(2*N-1):
		s = f.readline().split()
		for ss in s:
			if ss in mark:
				mark[ss] += 1
			else:
				mark[ss] = 1
	l=[]
	for k in mark:
		if mark[k] % 2 == 1:
			l.append(int(k))
	assert len(l) == N
	l=sorted(l)
	sys.stdout.write('Case #'+str(i+1)+":")
	for k in l:
		sys.stdout.write(' '+str(k))
	sys.stdout.write('\n')
