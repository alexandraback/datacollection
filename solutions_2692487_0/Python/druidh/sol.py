import sys

def read_ints():
	return map(int, sys.stdin.readline().split())
#	return [int(x) for x in sys.stdin.readline().split()]

def sol_motes(A, motes, ans_max):
	ans = 0
	for m in motes:
		if (m < A):
			A += m
			if (A > 1000000):
				break
		else:
			if (A == 1):
				return len(motes)
			else:
				while (A <= m):
					ans += 1
					if (ans > ans_max):
						return ans
					A += (A-1)
				A += m
	return ans

(T,) = read_ints()
for case in range(1, T + 1):
	A, N = map(int, sys.stdin.readline()[:-1].split(' '))
	motes = map(int, sys.stdin.readline()[:-1].split(' '))
	motes.sort()

	ans = len(motes)
	ans = sol_motes(A, motes, ans)
	for i in xrange(1, len(motes)+1):
		ans = min(ans, i + sol_motes(A, motes[:(-1)*i], ans))

	print "Case #%d: %s" % (case, ans)
	

