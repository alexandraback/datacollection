def solve(N, W):
    ans = 0
    for b in range(1<<N):
        ok = True
        S = [set(), set()]
        for i in range(N):
            if not b>>i&1:
                S[0].add(W[i][0])
                S[1].add(W[i][1])
        for i in range(N):
            if b>>i&1:
                if (W[i][0] not in S[0] or
                    W[i][1] not in S[1]):
                    ok = False
        if ok:
            ans = max(ans, sum(b>>i&1 for i in range(N)))
    return ans

for t in range(input()):
    N = input()
    W = [raw_input().split() for _ in range(N)]
    print "Case #%s: %s" % (t+1, solve(N, W))
