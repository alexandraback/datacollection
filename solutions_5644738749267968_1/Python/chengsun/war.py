#!/usr/bin/python3
T = int(input())
for t in range(1,T+1):
    n = int(input())
    nao = sorted(list(map(float, input().split())), reverse=True)
    ken = sorted(list(map(float, input().split())), reverse=True)
    assert len(nao) == len(ken) == n
    naoi, keni = 0, 0
    origeval = 0
    while naoi < n:
        assert keni < n
        if ken[keni] < nao[naoi]:
            origeval += 1
        else:
            keni += 1
        naoi += 1
    nao.reverse()
    ken.reverse()
    naoi, keni = 0, 0
    naowins = 0
    while naoi < n:
        assert keni < n
        if ken[keni] < nao[naoi]:
            naowins += 1
            keni += 1
        naoi += 1
    print("Case #{}: {} {}".format(t, naowins, origeval))
