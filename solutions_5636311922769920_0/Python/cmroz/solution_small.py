def solve(K,C,S):
	assert K == S # small input set
	return " ".join(map(str, range(1,K+1)))

if __name__ == '__main__':
	T = int(raw_input())
	for t in range(T):
		(K,C,S) = map(int, raw_input().split())
		print "case #%d: %s" % (t+1, solve(K,C,S))
