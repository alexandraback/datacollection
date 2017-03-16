T = int(raw_input())

def C(n):
	return (n*(n+1)/2)
def get(x, y):
	return C(x-1+2*y) - C(x-1)

TC = 1
while T > 0:
	str = raw_input().split()
	R = int(str[0])
	N = int(str[1])
	
	l = 1
	r = 1000000001
	ans = 1
	while l <= r:
		mid = (l + r) / 2
		if get(R, mid) <= N:
			ans = mid
			l = mid + 1
		else:
			r = mid - 1
	print "Case #%d: %d" % (TC, ans)
	T -= 1
	TC += 1