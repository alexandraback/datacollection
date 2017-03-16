def doit(K, C):
    ans = []
    if C > K:
        ans = 0
        for j in range(K):
            ans = K * ans + j
        for j in range(K, C):
            ans = K * ans
        return [str(ans + 1)]
    for i in range(0, K, C):
        tmp = 0
        for j in range(C):
            tmp = K * tmp + min(i + j, K-1)
        if tmp >= K**C:
            print("FUCK", tmp, K**C)
        ans.append(str(tmp + 1))
    return ans

T = int(input())
for t in range(T):
    K, C, S = [int(x) for x in input().strip().split()]
    ans = doit(K, C)
    if len(ans) > S:
        print("Case #%d: IMPOSSIBLE" % (t+1,))
    else:
        print("Case #%d: %s" % (t+1, ' '.join(ans)))
