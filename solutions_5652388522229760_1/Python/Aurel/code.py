T = int(raw_input())
for testId in range(T):
    N = int(raw_input())

    if N == 0:
        print "Case #{:d}: INSOMNIA".format(testId+1)
        continue

    seen = [False for i in xrange(10)]
    found = 0
    n = N
    while found < 10:
        for c in str(n):
            if not seen[int(c)]:
                seen[int(c)] = True
                found += 1
        if found < 10:
            n += N

    print "Case #{:d}: {:d}".format(testId+1, n)
