import sys

T = int(sys.stdin.readline())

def ans(r, t, lo, hi):
	while lo < hi:
		mid = (lo + hi) / 2
		val = t - (mid * (2 * r - 3) + 2 * mid * (mid + 1))
		#print lo, hi, val
		if val < 0:
			hi = mid
		elif val > 0:
			lo = mid + 1
		else:
			return mid
	return lo - 1


for i in range(1, T+1):
	r, t = [int(x) for x in sys.stdin.readline().split()]
	print "Case #" + str(i) + ": " + str(ans(r, t, 1, t))
