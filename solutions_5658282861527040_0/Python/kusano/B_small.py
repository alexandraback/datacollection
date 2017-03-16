def solve(A, B, K):
	r = 0
	for a in range(A):
		for b in range(B):
			if (a&b)<K:
				r += 1
	return r

for t in range(input()):
	A, B, K = map(int, raw_input().split())
	print "Case #%s: %s" % (t+1, solve(A,B,K))
