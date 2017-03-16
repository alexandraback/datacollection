def res(C, F, X):
	ans = 0.0
	for i in xrange(100000):
		if (X / (F*i + 2.0)) < (C / (F*i + 2.0) + X / (F*(i+1) + 2.0)):
			return ans + X / (F*i + 2.0)
		ans += C / (F*i + 2.0)

if __name__ == "__main__":
	T = int(raw_input())
	for t in xrange(T):
		C, F, X = map(float, raw_input().split())
		print "Case #%d: %.7f" % (t+1, res(C, F, X))