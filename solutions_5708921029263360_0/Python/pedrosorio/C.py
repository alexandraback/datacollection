from itertools import permutations
from collections import Counter

def solve_st(J, P, S, K):
	tup = []
	for i in xrange(1,J+1):
		for j in xrange(1,P+1):
			for k in xrange(1,S+1):
				tup.append((i, j, k))
	ct1, ct2, ct3 = Counter(), Counter(), Counter() 
	for v in tup:
		p1 = (v[0], v[1])
		p2 = (v[0], v[2])
		p3 = (v[1], v[2])
		ct1[p1] += 1
		ct2[p2] += 1
		ct3[p3] += 1
	ntup = []
	for v in tup:
		p1 = (v[0], v[1])
		p2 = (v[0], v[2])
		p3 = (v[1], v[2])
		if ct1[p1] > K and ct2[p2] > K and ct3[p3] > K:
			ct1[p1] -= 1
			ct2[p2] -= 1
			ct3[p3] -= 1
		else:
			ntup.append(v)
	tup = ntup[:]
	ntup = []
	for v in tup:
		p1 = (v[0], v[1])
		p2 = (v[0], v[2])
		p3 = (v[1], v[2])
		nums = [ct1[p1] > K, ct2[p2] > K, ct3[p3] > K]
		if sum([1 for c in nums if c]) == 2:
			ct1[p1] -= 1
			ct2[p2] -= 1
			ct3[p3] -= 1
		else:
			ntup.append(v)
	tup = ntup[:]
	ntup = []
	for v in tup:
		p1 = (v[0], v[1])
		p2 = (v[0], v[2])
		p3 = (v[1], v[2])
		if ct1[p1] > K or ct2[p2] > K or ct3[p3] > K:
			ct1[p1] -= 1
			ct2[p2] -= 1
			ct3[p3] -= 1
		else:
			ntup.append(v)
	return len(ntup), ntup

def solve(J, P, S, K):
	max_days = min(K * (J * P), J * P * S)
	tup = []
	if max_days == J * P * S:
		for i in xrange(1,J+1):
			for j in xrange(1,P+1):
				for k in xrange(1,S+1):
					tup.append((i, j, k))
		return len(tup), tup
	else:
		for i in xrange(1, J+1):
			for j in xrange(1, P+1):
				for k in xrange(1, K+1):
					tup.append((i, j, k))
		return len(tup), tup

T = int(raw_input())
for case in range(1, T+1):
	J, P, S, K = map(int, raw_input().split())
	md, sol = solve(J, P, S, K)
	print "Case #{}: {}".format(case, md)
	for c in sol:
		print ' '.join(map(str, c))
