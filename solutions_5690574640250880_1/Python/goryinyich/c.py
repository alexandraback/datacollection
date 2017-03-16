import sys

def gen(r, c, m):
	m = r*c - m
	ans = [['*' for i in range(c)] for j in range(r)]
	if min(r, c) == 1:
		for i in range(r):
			for j in range(c):
				if i*c + j < m:
					ans[i][j] = '.'
		ans[0][0] = 'c'
		return ans
	if m == 1:
		ans[0][0] = 'c'
		return ans
	ans[0][0] = '.'
	ans[0][1] = '.'
	ans[1][0] = '.'
	ans[1][1] = '.'
	rr = 2
	cc = 2
	filled = 4
	while filled + 2 <= m:
		if rr < r and (rr <= cc or cc == c):
			filled += 2
			ans[rr][0] = '.'
			ans[rr][1] = '.'
			rr += 1
		elif cc < c:
			filled += 2
			ans[0][cc] = '.'
			ans[1][cc] = '.'
			cc += 1
		else:
			break
	for i in range(2,rr):
		for j in range(2,cc):
			if filled+1 <= m:
				filled += 1
				ans[i][j] = '.'
			else:
				break
	ans[0][0] = 'c'
	if filled != m:
		return 'Impossible'
	return ans

tc = int(sys.stdin.readline())
for t in range(tc):
	s = sys.stdin.readline().split()
	ans = gen(int(s[0]), int(s[1]), int(s[2]))
	if ans != 'Impossible':
		ans = '\n'.join([''.join([c for c in ans[i]]) for i in range(len(ans))])
	print 'Case #%d:\n' % (t+1) + ans
