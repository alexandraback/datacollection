# 2345
import random
R,N,M,K = 100,3,5,7

d = {}
p = [2,3,4,5]
for i in p:
	for j in p:
		if j < i:
			continue
		for k in p:
			if (k < i or k < j):
				continue
			x = (i,j,k)
			for q in (1,i,j,k,i*j,j*k,k*i,i*j*k):
				d.setdefault(q,set()).add(x)

p = 2,3,4,5
def solve(muls):
	#print 'solve'
	candidates = d[muls[0]].copy()
	#print candidates
	for m in muls[1:]:
		candidates &= d[m]
		#print m, d[m]
	#print candidates
	return random.choice(list(candidates))
T = input()
R, N, M, K = [int(x) for x in raw_input().split()]
print 'Case #1:'
for loop in xrange(R):
	v = [int(x) for x in raw_input().split()]
	print ''.join(str(x) for x in solve(v))


