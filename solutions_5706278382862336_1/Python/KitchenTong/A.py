def gcd(a, b):
	if a % b == 0:
		return b
	return gcd(b, a % b)

def res(P, Q):
	for i in xrange(0, 41):
		if P / Q >= 1:
			p = P % Q
			if p * 2**(40-i) % Q == 0:
				return i
			pass
		P = P * 2
	return 99

if __name__ == "__main__":
	T = int(raw_input())
	for t in xrange(T):
		P, Q = map(int, raw_input().split('/'))
		factor = gcd(P, Q)
		P, Q = P / factor, Q / factor
		result = res(P, Q)
		print "Case #%d: %s" % (t+1, str(result) if result < 99 else 'impossible')