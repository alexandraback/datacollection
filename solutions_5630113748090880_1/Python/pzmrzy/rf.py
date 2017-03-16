#!/usr/bin/python
def fill(M,l,v1,v2):
	pass
fin = open('B-large.in')
T = int(fin.readline())
for ii in range(T):
	N = int(fin.readline().strip())
	data = []
	mat = [0] * 2501
	M = [[0] * N] * N
	for i in range(2*N-1):
		tmp = []
		for t in fin.readline().strip().split(' '):
			tmp.append(int(t))
			mat[int(t)] += 1
		data.append(tmp)
	r = []
	data.sort()
	for i in range(2501):
		if not (mat[i] % 2 == 0):
			r.append(i)
	r.sort()
	result = ""
	for n in r:
		result += "%s " % n

	print "Case #%s: %s" % (ii + 1, result.strip())
fin.close()