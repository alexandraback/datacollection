def solve(K, C, S):
    if K == 1:
        return [1]
    if C == 1:
        return range(1, K+1) if S >= K else None
    return range(2, K + 1) if S >= K - 1 else None

with open("fractiles.in") as fin:
    T = int(fin.readline())
    for t in xrange(T):
        K, C, S = map(int, fin.readline().split())
        res = solve(K, C, S)
        ans = " ".join(map(str, res)) if res else "IMPOSSIBLE"
        print "Case #%d: %s" % (t+1, ans)
