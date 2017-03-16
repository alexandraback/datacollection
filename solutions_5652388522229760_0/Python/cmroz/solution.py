def solve(N):
	if N == 0:
		return "INSOMNIA"
	k = 0
	seen = set()
	while len(seen) < 10:
		k += N
		seen |= set(str(k))
	return k

if __name__ == '__main__':
	T = int(raw_input())
	for t in range(T):
		N = int(raw_input())
		print "case #%d: %s" % (t+1,solve(N))
