
def solve(a, sizes):
    dp = {}
    def _solve(curr, i):
        if (curr, i) in dp:
            return dp[curr, i]
        if i >= len(sizes):
            return 0
        if sizes[i] < curr:
            dp[curr, i] = _solve(curr + sizes[i], i+1)
            return dp[curr, i]
        else:
            if curr > 1:
                val1 = 1 + _solve(curr + curr - 1, i)
            else:
                val1 = 1e10
            val2 = 1 + _solve(curr, i+1)
            dp[curr, i] = min(val1, val2)
            return dp[curr, i]

    sizes.sort()
    return _solve(a, 0)

T = int(raw_input())
for t in xrange(1, T+1):
    A, _ = [long(x) for x in raw_input().split()]
    sizes = [long(x) for x in raw_input().split()]
    print 'Case #{}: {}'.format(t, solve(A, sizes))
