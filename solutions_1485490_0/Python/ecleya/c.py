import sys

rl = sys.stdin.readline
T = int(rl())

for i in range(0, T):
	N, M = map(int, rl().split(' '))
	route = []
	
	A = map(int, rl().split(' '))
	B = map(int, rl().split(' '))
	
	A.extend([-1, -1])
	B.extend([-1, -1])
	
	for idx in range(0, N):
		if idx >= N:
			break
		while(A[idx * 2 + 1] == A[idx * 2 + 3]):
			A[idx * 2] = A[idx * 2] + A[idx * 2 + 2]
			for j in range(idx + 1, N):
				A[j * 2] = A[j * 2 + 2]
				A[j * 2 + 1] = A[j * 2 + 3]
			N = N - 1
	
	for idx in range(0, M):
		if idx >= M:
			break
		while(B[idx * 2 + 1] == B[idx * 2 + 3]):
			B[idx * 2] = B[idx * 2] + B[idx * 2 + 2]
			for j in range(idx + 1, M):
				B[j * 2] = B[j * 2 + 2]
				B[j * 2 + 1] = B[j * 2 + 3]
			M = M - 1
	mem = {}
	
	def solve(a1, a2, b1, b2):
		if a1 >= N * 2 or b1 >= M * 2:
			return 0
		
		if mem.has_key((a1, a2, b1, b2)):
			return mem[(a1, a2, b1, b2)]

		res = 0
		if A[a1] == B[b1]:
			cnt = min(a2, b2)
			if a2 < b2:
				res = solve(a1 + 2, A[a1 + 1], b1, b2 - cnt) + cnt
			elif a2 > b2:
				res = solve(a1, a2 - cnt, b1 + 2, B[b1 + 1]) + cnt
			else:
				res = solve(a1 + 2, A[a1 + 1], b1 + 2, B[b1 + 1]) + cnt
		else:
			b = b1 + 2
			while(b < M * 2 and B[b] != A[a1]):
				b = b + 2
				
			res = max(res, solve(a1, a2, b, B[b - 1]))

		a = a1 + 2
		while(a < N * 2 and A[a] != B[b1]):
			a = a + 2
			
		res = max(res, solve(a, A[a - 1], b1, b2))
		
		res = max(res, solve(a1 + 2, A[a1 + 1], b1, b2))
		
		mem[(a1, a2, b1, b2)] = res
		return res

	print 'Case #%d: %d' % (i + 1, solve(1, A[0], 1, B[0]))
	