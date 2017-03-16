T = int(raw_input())

for i in range(T):
    k, c, s = map(int, raw_input().split())
    d = min(k, c)
    xs = range(k)

    r = []
    while xs:
        j = 0
        for _ in range(c):
            j *= k
            if xs: j += xs.pop(0)
            # print j
        # print
        r.append(str(j+1))


    print "Case #%d:" % (i + 1),
    if len(r) > s: print "IMPOSSIBLE"
    else: print ' '.join(r)
