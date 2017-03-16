T = int(raw_input())

for i in range(T):
    n = int(raw_input())
    on = n
    seen = set()
    if n == 0:
        print "Case #%d: INSOMNIA" % (i+1)
        continue
    while 1:
        for c in str(n): seen.add(c)
        if len(seen) == 10: break
        if n >= 1000000:
            break
        n += on
    print "Case #%d: %d" % (i+1, n)

