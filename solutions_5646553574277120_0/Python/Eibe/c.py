def ch(ds):
    cng = set()
    for msk in range(1, 2 ** len(ds)):
        cnt = 0
        pos = 0
        while msk:
            if msk%2 == 1:
                cnt += ds[pos]
            msk /= 2
            pos += 1
        cng.add(cnt)
    return cng

t = int(raw_input())
for case in range(1, t+1):
    c, d, v = map(int, raw_input().split())
    ds = map(int, raw_input().split())
    cnt = 0
    while len(ds) < v:
        change = ch(ds)
        for m in range(1, v+1):
            if m not in change:
                break
        else:
            break
        ds.append(m)
        cnt += 1
    print "Case #%i: %i" %(case, cnt)
