import sys

def solve(r, c, m):
	t = [['*' for j in xrange(c)] for i in xrange(r)]
	t[0][0] = 'c'
	
	cl = r*c - m
	if m < 0 or cl <= 0:
		return None
	if cl == 1:
		return t

	if r == 1:
		for j in xrange(1, cl):
			t[0][j] = '.'
		return t

	for a in xrange(2, r+1):
		for b in xrange(2, c+1):
			l = a*b - (a-2)*(b-2) 
			if l <= cl and cl <= a*b:
				for i in xrange(a):
					t[i][0] = t[i][1] = '.'
				for j in xrange(b):
					t[0][j] = t[1][j] = '.'
				t[0][0] = 'c'
				cl = cl - l
				for i in xrange(2, a):
					for j in xrange(2, b):
						if cl > 0:
							t[i][j] = '.'
							cl = cl - 1
				if cl == 0:
					return t
	return None

data = [map(int, line.split()) for line in sys.stdin.readlines()]
tn = data[0][0]
for ti in xrange(tn):
	(r, c, m) = data[ti+1]
	trans = False
	if r > c:
		(r, c) = (c, r)
		trans = True
	t = solve(r, c, m)
	print "Case #%d:" % (ti+1)
	if t != None:
		if trans:
			t = zip(*t)
		for line in t:
			print ''.join(line)
	else:
		print "Impossible"
