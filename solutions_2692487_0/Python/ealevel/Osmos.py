import sys
sys.setrecursionlimit(10001)

def dfs(val, idx):
	if (val, idx) in table:
		return table[val, idx]
	if idx == n:
		return 0
	if motes[idx] < val:
		return dfs(val + motes[idx], idx + 1)

	ans1 = n - idx # remove rest
	ans2 = 1 + dfs(2 * val - 1, idx) # add max possible mote
	
	table[val, idx] = min(ans1, ans2)
	return table[val, idx]

T = int(sys.stdin.readline().strip())
for t in xrange(1, T+1):
	a, n = map(int, sys.stdin.readline().strip().split())
	motes = map(int, sys.stdin.readline().strip().split())
	motes.sort()
	table = {}
	print "Case #{}: {}".format(t, dfs(a, 0) if a > 1 else n)
