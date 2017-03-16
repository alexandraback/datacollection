from itertools import *

N = 3
A = [2,3,4,5]

ignore = raw_input()
print "Case #1:"
[R, N, M, K] = map(int, raw_input().split())


def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def gen(d):
	if d == 1:
		return [[x] for x in A]
	else:
		B = []
		P = gen(d-1)
		for a in A:
			B += [x + [a] for x in P]
		return B

def ps(a):
	p = {}

	for s in powerset(a):
		prod = 1
		for x in s:
			prod *= x
		if prod not in p:
			p[prod] = 0

		p[prod] += .125
	return p

def likl(a, ns):
	p = ps(a)
	tot = 0
	for x in ns:
		if x not in p:
			return 0
		tot += p[x]
	return tot



for c in range(R):
	poss = gen(N)
	ns = map(int, raw_input().split())
	b = sorted(poss, key=lambda a: likl(a, ns))
	b.reverse()
	print ''.join(map(str,b[0]))