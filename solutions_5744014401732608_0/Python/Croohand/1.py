t = int(input())

def cnt(n, g):
	k = [0 for i in range(n)]
	k[0] = 1
	for i in range(n):
		for j in range(n):
			if g[i][j]:
				k[j] += k[i]
	return k[-1]

for test in range(t):
	print('Case #%d: ' % (test + 1), end = '')
	n, m = map(int, input().split())
	g = [[(i < j) for j in range(n)] for i in range(n)]
	cur = cnt(n, g)
	if cur < m:
		print('IMPOSSIBLE')
		continue
	print('POSSIBLE')
	while cur > m:
		bi = -1
		bj = -1
		mx = -1
		found = False
		for i in range(n):
			for j in range(n):
				if not found and g[i][j]:
					g[i][j] = False
					nxt = cnt(n, g)
					if nxt >= m and cur - nxt > mx:
						mx = cur - nxt
						bi = i
						bj = j
						found = 1
					g[i][j] = True
		g[bi][bj] = False 
		cur = cnt(n, g)
	for i in g:
		for j in i:
			print(int(j), end = '')
		print()
