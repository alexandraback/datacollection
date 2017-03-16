T = int(raw_input())

for keis in xrange(T):
	A,N = [int(x) for x in raw_input().split()]
	arr = [int(x) for x in raw_input().split()]
	arr.sort()
	cache = {}
	def f(n,k):
		# print((n,k))
		if n == N:
			return 0
		if (n,k) not in cache:
			if arr[n] < k:
				cache[(n,k)] = f(n+1,k+arr[n])
			else:
				cache[(n,k)] = min(f(n,k+k-1)+1, f(n+1,k)+1)
		return cache[(n,k)]
	if A == 1:
		print('Case #%d: %d' % (keis+1, N))
	else:
		print('Case #%d: %d' % (keis+1, f(0,A)))


