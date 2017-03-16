n = int(raw_input())
for t in xrange(n):
	(r,c,mm) = map(int,raw_input().split())
	m = r*c-mm
	ok = True
	x = []
	for i in xrange(r):
		x.append(['*']*c)
	if m == 1:
		pass
	elif r == 1 or c == 1:
		for i in xrange(m):
			if r == 1:
				x[0][i] = '.'
			else:
				x[i][0] = '.'
	elif r == 2 or c == 2:
		if m % 2 == 1 or m == 2:
			ok = False
		else:
			for i in xrange(m/2):
				if r == 2:
					x[0][i] = '.'
					x[1][i] = '.'
				else:
					x[i][0] = '.'
					x[i][1] = '.'
	elif m >= 8 or m == 4 or m == 6:
		if m >= 2*c+2:
			for i in xrange(r):
				for j in xrange(max(0,min(c,m-c*i))):
					x[i][j] = '.'
			if m % c == 1:
				x[m/c][1] = '.'
				x[m/c-1][c-1] = '*'
		else:
			for i in xrange(m/2):
				x[0][i] = '.'
				x[1][i] = '.'
			if m % 2 == 1:
				x[2][0] = '.'
				x[2][1] = '.'
				x[2][2] = '.'
				x[0][m/2-1] = '*'
				x[1][m/2-1] = '*'
	else:
		ok = False
	x[0][0] = 'c'
	print 'Case #'+str(t+1)+':'
	if ok:
		for row in x:
			print ''.join(row)
	else:
		print 'Impossible'
