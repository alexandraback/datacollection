
def rl():
	return map(int,raw_input().split())

def solve(r,t):
	low = 0
	high = t
	while low < high:
		mid = (low+high+1)/2
		s = mid*(2*mid+2*r-1)
		if s <= t: # ok
			low = mid
		else:
			high = mid -1
	return low

def main():
	(T,) = rl()
	for i in range(1,T+1):
		r,t = rl()
		n = solve(r,t)
		print 'Case #%d: %d'%(i,n)

main()