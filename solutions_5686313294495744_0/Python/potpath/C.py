from collections import Counter

T = int(input())
for t in range(1, T + 1):
    N = int(input())
    aa = []
    bb = []
    for i in range(N):
        a, b = input().split()
        aa.append(a)
        bb.append(b)
    caa = Counter(aa)
    cbb = Counter(bb)
    seta = set(aa)
    setb = set(bb)
    useda = set()
    usedb = set()
    remaini = set(range(N))
    ans = 0
    for i, (a, b) in enumerate(zip(aa, bb)):
        if caa[a] == 1 or cbb[b] == 1:
            useda.add(a)
            usedb.add(b)
            remaini.remove(i)
            try:
                seta.remove(a)
            except KeyError:
                pass
            try:
                setb.remove(b)
            except KeyError:
                pass
            ans += 1
    minans = 0
    while True:
        for i in remaini:
            a, b = aa[i], bb[i]
            if a in useda and b in usedb:
                minans += 1
                remaini.remove(i)
                try:
                    seta.remove(a)
                except KeyError:
                    pass
                try:
                    setb.remove(b)
                except KeyError:
                    pass
                break
        else:
            break
    # print((len(seta) + len(setb)))
    # print(N, ans)
    ans += (len(seta) + len(setb)) / 2
    print('Case #%d: %d' % (t, N - ans))
