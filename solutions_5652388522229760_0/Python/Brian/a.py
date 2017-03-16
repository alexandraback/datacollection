with open("a.in") as f:
    t = int(next(f))
    for case in xrange(t):
        seen = set()
        n = int(next(f))

        if n == 0:
            print "Case #{}: INSOMNIA".format(case+1)
            continue

        sheep = 0
        while len(seen) < 10:
            sheep += n
            s = str(sheep)
            for c in s:
                seen.add(c)

        print "Case #{}: {}".format(case+1, sheep)
