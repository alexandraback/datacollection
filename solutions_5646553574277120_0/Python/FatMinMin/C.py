T = int(raw_input())

for ca in xrange(1, T + 1):
    c, d, v = map(int, raw_input().split())
    de = map(int, raw_input().split())

    ck = [False] * (v + 1)
    for x in de:
        ck[x] = True
    for i in xrange(d):
        for j in xrange(i + 1, d):
            tmp = de[i] + de[j]
            if tmp <= v:
                ck[tmp] = True
    flag = True
    gg = []
    for x in xrange(1, v + 1):
        if not ck[x]:
            gg.append(x)
            flag = False
    ans = 0
    while not flag:

        total = {}
        for x in gg:
            total[x] = total.get(x, 0) + 1
            for y in de:
                if x - y > 0:
                    total[x - y] = total.get(x - y, 0) + 1

        best = (-1, 0)
        for k in total:
            if total[k] > best[1]:
                best = (k, total[k])

        de.append(best[0])
        d = len(de)
        for x in de:
            ck[x] = True
        for i in xrange(d):
            for j in xrange(i + 1, d):
                tmp = de[i] + de[j]
                if tmp <= v:
                    ck[tmp] = True
        flag = True
        gg = []
        for x in xrange(1, v + 1):
            if not ck[x]:
                gg.append(x)
                flag = False
        ans += 1

    print 'Case #{}: {}'.format(ca, ans)
