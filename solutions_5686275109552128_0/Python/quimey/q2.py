T = input()
for t in range(T):
    D = input()
    P = map(int, raw_input().split())
    m = 10000
    for h in range(1,1001):
        c = 0
        o = 0
        for p in P:
            c += (p-1)/h
            if p>=h:
                o = h
            o = max(o, h-(h-p)%h)
        # print h,c,o
        m = min(m, c + o)
    print "Case #%d: %d" % (t + 1, m)
