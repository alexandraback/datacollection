T = int(input())

for case in range(1, T + 1):
    sp = input().split()
    K = int(sp[0])
    C = int(sp[1])
    S = int(sp[2])

    if S * C < K:
        print("Case #{0}: IMPOSSIBLE".format(case))
        continue
    ans = []

    query = []
    res = []
    for i in range(K):
        res.append(i)
        if len(res) == C:
            query.append(res)
            res = []
    if len(res) > 0:
        query.append(res)

    for i in query:
        ll = 0
        rr = K**C - 1
        div = K**C
        for j in i:
            div //= K
            a = (ll - j * div - 1) // (div * K) + 1
            ll = a * div * K + j * div
            rr = a * div * K + j * div + div - 1
            #print("{0} {1}".format(ll, rr))

        ans.append(str(ll + 1))

    print("Case #{0}: {1}".format(case, ' '.join(ans)))


