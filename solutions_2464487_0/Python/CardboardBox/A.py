def solve(r,t):
	high = 1
	while high*(2*high+2*r-1) <= t:
		high *= 2
	low = 1
	while low < high-1:
		mid = (low+high)/2
		extra = t - mid*(2*mid+2*r-1)
		if extra == 0:
			return mid
		elif extra > 0:
			low = mid
		else:
			high = mid
	return low

n_cases = input()
for case in range(1,n_cases+1):
	r,t = map(int,raw_input().split())
	print 'Case #%d: %d' % (case, solve(r,t))