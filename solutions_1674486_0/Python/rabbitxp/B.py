#!/usr/bin/env python

_FMT_ = 'Case #%d: %s\n'
f = open('in','r')
_T_ = int(f.readline())
g = open('out','w')

for _t_ in xrange(_T_): 

	#INPUT
	N = int(f.readline())
	total = []
	full = []
	size = 0
	for n in xrange(N):
		total.append(n)
	for n in xrange(N):
		line = f.readline().strip().split()
		M = int(line[0])
		nn=[]
		if M>0:
			size += M
			mink = total[n]
			for m in xrange(M):
				k = int(line[m+1])-1
				if total[k] < mink: mink = total[k]
				nn.append(k)
			total[n] =mink
			for nnn in nn:
				total[nnn] = mink
		full.append(nn)
	n_sets = 0
	for n in xrange(N):
		for t in xrange(N):
			mink = total[t]
			for k in full[t]:
				if total[k]  < mink: mink = total[k]
			total[t] = mink
			for k in full[t]:
				total[k] = mink
	for n in xrange(N):
		if total[n] == n: n_sets += 1
	result = 'Yes'
	if size + n_sets <= N: result ='No' 

	#OUTPUT
	print _t_, result
	g.write(_FMT_ %(_t_+1, str(result)))

