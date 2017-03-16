def go(K, C, S):
    need = (K - 1) // C + 1
    if need > S:
        return 'IMPOSSIBLE'
    res = []
    branches = list(range(K))
    for i in range(0, K, C):
        cur = 0
        for branch in branches[i:i + C]:
            cur = K*cur + branch
        res.append(cur)
    return ' '.join(str(cur + 1) for cur in res)

T = int(input())
for tc in range(T):
    K, C, S = map(int, input().split())
    print("Case #{}: {}".format(tc + 1, go(K, C, S)))
