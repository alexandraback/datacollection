import itertools

def dist(p):
	s = ''.join(p)
	x1 = int(s[:len(s)//2])
	x2 = int(s[len(s)//2:])
	return abs(x1-x2)

#assuming d=0
def better(p1, p2):
	s1 = ''.join(p1)
	c1 = int(s1[:len(s1)//2])
	j1 = int(s1[len(s1)//2:])
	s2 = ''.join(p2)
	c2 = int(s2[:len(s2)//2])
	j2 = int(s2[len(s2)//2:])
	if c1 < c2:
		return p1
	elif c1 > c2:
		return p2
	if j1 < j2:
		return p1
	else:
		return p2

def optimal(po):
	minsol = None
	mind = 10**20
	for p in itertools.product(*po):
		if dist(p) < mind:
			mind = dist(p)
			minsol = p
		elif dist(p) == mind:
			minsol = better(minsol,p)
	s = ''.join(minsol)
	return s[:len(s)//2], s[len(s)//2:]

def solve(c,j):
	l = len(c)
	p = [tuple()]*2*l
	for i in range(l):
		if c[i] == '?':
			if j[i] == '?':
				p[i] = ('0','1','9')
				p[i+l] = ('0','1','9')
			else:
				n = int(j[i])
				p[i] = tuple(set([str(x) for x in (0, 9, (n-1)%10, n, (n+1)%10)]))
				p[i+l] = tuple(j[i])
		else:
			p[i] = tuple(c[i])
			if j[i] == '?':
				n = int(c[i])
				p[i+l] = tuple(set([str(x) for x in (0, 9, (n-1)%10, n, (n+1)%10)]))
			else:
				p[i+l] = tuple(j[i])
	#print(p)
	return optimal(p)

tc = int(input())
for t in range(1,tc+1):
	(c,j) = input().split()
	cc, jj = solve(c,j)
	print('Case #{}: {} {}'.format(t,cc,jj))
