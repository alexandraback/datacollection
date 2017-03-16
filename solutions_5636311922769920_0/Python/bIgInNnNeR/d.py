T = int(input())
for tn in range(1, T + 1):
    K, C, S = map(int, input().split())
    if S * C < K:
        print("Case #%d: IMPOSSIBLE" % tn)
    else:
        ans = []
        cur = 0
        while cur < K:
            now = 0
            for deep in range(C):
                now += (K ** (C - deep - 1)) * min(cur, K - 1)
                cur += 1
            ans.append(now + 1)
        print("Case #%d:" % tn, *ans)
