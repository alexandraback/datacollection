import sys
t = input()
p = [(0, 0), (1, 0), (0, 1), (1, 1), (0, 2), (1, 2), (2, 0), (2, 1)]
for tt in range(t):
	print "Case #%d:"%(tt + 1)
	r, c, m = map(int, raw_input().split())
	reverse = False
	solution = True
	if r > c:
		r, c = c, r
		reverse = True
	z = [[0] * c for i in range(r)] 
	if r == 1:
		for i in range(m):
			z[0][c - 1 - i] = 1
	elif r == 2:
		if m == r * c - 1:
			for i in range(c):
				z[0][i] = 1
				z[1][i] = 1
			z[0][0] = 0
		elif m % 2 == 1 or m == r * c - 2:
			solution = False
		else:
			for i in range(m/2):
				z[0][c - 1 - i] = 1
				z[1][c - 1 - i] = 1
	else:
		m = r * c - m
		if m in [2, 3, 5, 7]:
			solution = False
		else:
			z = [[1] * c for i in range(r)] 
			for (i, j) in p:
				if m == 0:
					break
				z[i][j] = 0
				m -= 1
			for i in range(3, c):
				if m < 2:
					break
				z[0][i] = 0
				z[1][i] = 0
				m -= 2
			for i in range(3, r):
				if m < 2:
					break
				z[i][0] = 0
				z[i][1] = 0
				m -= 2
			for i in range(2, r):
				for j in range(2, c):
					if m == 0:
						break
					z[i][j] = 0
					m -= 1
				else:
					continue
				break
	if solution == False:
		print "Impossible"
		print >>sys.stderr, r, c, m
	else:
		if reverse == True:
			a = [[0] * r for i in range(c)] 
			for i in range(r):
				for j in range(c):
					a[j][i] = z[i][j]
			z = a
			r, c = c, r
		for i in range(r):
			s = ""
			for j in range(c):
				if z[i][j] == 1:
					s += "*"
				else:
					if i == 0 and j == 0:
						s += "c"
					else:
						s += "."
			print s


