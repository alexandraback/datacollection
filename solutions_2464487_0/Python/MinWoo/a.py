
def sum_to_n(n, r):
	res = 2*r*n
	res += n*(2+(n-1)*4)/2
	return res

def solve(r, t):
	lo, hi = 0, 10**20
	while lo+1 < hi:
		mid = (lo + hi) / 2
		#print lo, hi, mid, sum_to_n(mid, r)
		if sum_to_n(mid, r) <= t:
			lo = mid
		else:
			hi = mid
	return lo

T = input()
for tc in xrange(T):
	r, t = map(int, raw_input().split())
	print 'Case #%d: %d' % (tc+1, solve(r, t))

