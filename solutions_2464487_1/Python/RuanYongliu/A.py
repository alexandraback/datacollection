def f(A, B, mid):
	return A * (mid ** 2) + B * mid

def binary(A, B, t):
	L = 1
	R = 1000000000
	while L < R:
		mid = (L + R + 1) / 2
		if f(A, B, mid) > t:
			R = mid - 1
		else:
			L = mid
	return L

T = int(raw_input())
for cas in xrange(1, T + 1):
	r, t = map(int, raw_input().split())
	A = 2
	B = 2 * r - 1
	g = binary(A, B, t)
	print "Case #{0}: {1}".format(cas, g)
