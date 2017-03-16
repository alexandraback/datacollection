t = input()
for i in range(t):
	n, m = [int(a) for a in raw_input().split()]
	p = []
	for j in range(n):
		p.append([int(a) for a in raw_input().split()])
	
	c = []
	l = []
	for j in range(n):
		x = 0
		for k in range(m):
			if x < p[j][k]:
				x = p[j][k]
		l.append(x)
	
	for j in range(m):
		x = 0
		for k in range(n):
			if x < p[k][j]:
				x = p[k][j]
		c.append(x)
	
	possible = True
	for j in range(n):
		for k in range(m):
			if p[j][k] < c[k] and p[j][k] < l[j]:
				possible = False
				break
		if not possible:
			break
	
	if possible:
		res = 'Case #%d: YES' %(i+1)
	else:
		res = 'Case #%d: NO' %(i+1)
	
	print res

			