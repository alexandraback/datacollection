import sys
sys.setrecursionlimit(10001)

T = int(sys.stdin.readline().strip())
for case in xrange(1, T+1):
	r, t = map(int, sys.stdin.readline().strip().split())
	
	c = 1
	ans = 0
	while True:
		A = (r + c) ** 2 - (r + c - 1) ** 2
		c += 2
		if A <= t:
			t -= A
			ans += 1
		else:
			break

	print "Case #{}: {}".format(case, ans)
