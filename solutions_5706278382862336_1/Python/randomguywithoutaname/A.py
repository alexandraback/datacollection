def gcd(a, b):
	if (a < b):
		return gcd(b, a)
	if (b == 0):
		return a
	return gcd(b, a % b)

T = int(input())
for I in range(1, T+1):
	A, B = input().split("/")
	P, Q = int(A), int(B)
	
	den = gcd(P, Q)
	p, q = P/den, Q/den
	
	result = 0
	pow = 1
	while pow <= q:
		if pow == q:
			break
		pow *= 2
		result += 1
	
	if pow != q:
		print("Case #%d: %s" % (I,"Impossible"))
	else:
		result = 1
		while p < q/2:
			p *= 2
			result += 1
		print("Case #%d: %d" % (I,result))