def solve(K, C, S):
    ans = []
    k = 0
    while k<K:
        x = 0
        for c in range(C):
            x = K*x + min(k, K-1)
            k += 1
        ans += [x]
    return " ".join(str(a+1) for a in ans) if len(ans)<=S else "IMPOSSIBLE"

for t in range(input()):
    K,C,S = map(int, raw_input().split())
    print "Case #%s: %s" % (t+1, solve(K,C,S))
