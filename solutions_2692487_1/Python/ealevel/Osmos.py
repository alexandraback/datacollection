import sys, math
 
def fast_dp(motes, i, current):
        if i >= len(motes):
                return 0
        if current > motes[i]:
                return fast_dp(motes, i+1, current + motes[i])
        if current == 1:
                return len(motes) - i
        return min(len(motes) - i, 1 + fast_dp(motes, i, 2 * current - 1))
 
T = int(sys.stdin.readline().strip())
for t in xrange(1, T+1):
	A, n = map(int, sys.stdin.readline().strip().split())
	motes = map(int, sys.stdin.readline().strip().split())
	motes.sort()
	print "Case #{}: {}".format(t, fast_dp(motes, 0, A))
