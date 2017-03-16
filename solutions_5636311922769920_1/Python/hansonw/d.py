T = int(raw_input())

for t in range(T):
    print 'Case #%d:' % (t + 1),
    K, C, S = map(int, raw_input().split())
    ans = (K + C - 1) // C
    if ans > S:
        print 'IMPOSSIBLE'
        continue

    res = []
    for i in range(ans):
        x = 0
        for j in range(C):
            idx = min(K - 1, i * C + j)
            x += idx * (K ** (C - 1 - j))
        res.append(x + 1)
    print ' '.join(map(str, res))
