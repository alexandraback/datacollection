import math

def check(n):
	return ((2*n*r + 2*(n**2) - n)) > t

T = input()
for case_no in range(1, T+1):
	r, t = map(int, raw_input().split())
	lo, hi = 1, 10**18
	#print check(1), check(2)
	while lo + 1 < hi:
		mid = (lo + hi)/2
		if check(mid):
			hi = mid - 1
		else:
			lo = mid
	if check(hi):
		hi = lo
	print 'Case #%i: %i' % (case_no, hi)