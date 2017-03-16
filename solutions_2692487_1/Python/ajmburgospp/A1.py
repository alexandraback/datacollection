T = int(raw_input())

for keis in xrange(T):
	A,N = [int(x) for x in raw_input().split()]
	arr = [int(x) for x in raw_input().split()]
	arr.sort()
	#print(arr)
	def pos(n):
		curr = A
		for i in xrange(N):
			#print('***')
			#print(arr[i], N)
			#print('---')
			if arr[i] < curr:
				curr += arr[i]
			else:
				if N-i <= n:
					return True
				else:
					while curr <= arr[i] and n >= 0:
						#print('try')
						#print(curr,n)
						curr += curr - 1
						n -= 1
					#print(curr,n)
					if n < 0:
						return False
					curr += arr[i]
		return n >= 0
	left, right = -1, N
	#print(left,right)
	while left+1 < right:
		mid = (left+right)/2
		#print('mid = %d' % (mid))
		if pos(mid):
			right = mid
		else:
			left = mid
		#print(left,right)
	print('Case #%d: %d' % (keis+1, right))
