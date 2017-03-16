
def solve(n,m):

	if 2**(n-2) < m:
		return 'IMPOSSIBLE',[]
	else:
		mat = [[0]*(i+1) + [1] *(n-i-1) for i in range(n)]
		mat[0] = [0]*n


		if m == 0:
			pass 
		else:
			x = m - 1
			mat[0][n-1] = 1
			b = bin(x)[2:]
			
			for i,c in enumerate(b[::-1]):
				if c=='1':
					mat[0][n-2-i] = 1

		return 'POSSIBLE',mat


T = int(raw_input())

for i in range(T):
	n,m = [long(x) for x in raw_input().split()]

	result_str,mat = solve(n, m)
	if result_str == 'IMPOSSIBLE':
		print 'Case #{}: {}'.format(i+1,result_str)
	else:
		print 'Case #{}: {}'.format(i+1,result_str)
		for line in mat:
			print ''.join(map(str,line))
