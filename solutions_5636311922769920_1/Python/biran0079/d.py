T = int(raw_input())
for i in range(T):
    K,C,S = map(int, raw_input().split())
    if C * S < K:
        ans = "IMPOSSIBLE"
    else:
        def f(l):
            res = 0
            for t in l:
                res *= K
                res += t
            return str(res + 1)
        ans = " ".join(map(f, [range(K)[j : C + j] for j in range(0, K, C)]))
    print "Case #{}: {}".format(i+1, ans)
