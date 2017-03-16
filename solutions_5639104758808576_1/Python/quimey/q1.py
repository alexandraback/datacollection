T = input()
for t in range(T):
    f = raw_input().split()
    s = int(f[0])
    v = [int(x) for x in f[1]]
    c = 0
    r = 0
    for i in range(s+1):
        if i>c:
            r += i - c
            c += i - c
        c += v[i]
    print "Case #%d: %d" % (t+1, r)
