def solve():
    n = int(input())
    f = list(map(int, input().split()))
    for i in range(n):
        f[i] -= 1

    def sizec(c):
        res = 2
        s, e = c
        while f[s] != e:
            res += 1
            s = f[s]
        return res

    cykly = []
    sl = []
    wassi = set()
    for si in range(n):
        if si in wassi:
            continue
        pred = -1
        cur = si
        was = set()
        was.add(cur)
        wassi.add(cur)
        cesta = [si]
        while True:
            ne = f[cur]
            wassi.add(ne)
            if ne in was:
                if ne == pred:
                    sl.append(tuple(cesta))
                else:
                    cykly.append((ne, cur))
                break
            else:
                cesta.append(ne)
                was.add(ne)
                pred = cur
                cur = ne

    res = 0
    for c in cykly:
        res = max(res, sizec(c))
    for c in sl:
        res = max(res, len(c))

    # print(sl)
    ml = dict()
    for x in sl:
        t = (x[-2], x[-1])
        if t not in ml or len(ml[t]) < len(x):
            ml[t] = x
    r = 0
    used = set()
    for k, v in ml.items():
        t2 = (k[1], k[0])
        if k in used or t2 in used:
            continue
        used.add(k)
        used.add(t2)
        if t2 in ml:
            r += len(v) + len(ml[t2]) - 2
        else:
            r += len(v)
    # print(ml)
    res = max(r, res)

    return res


t = int(input())
for tt in range(1, t + 1):
    print("Case #" + str(tt) + ":", solve())
