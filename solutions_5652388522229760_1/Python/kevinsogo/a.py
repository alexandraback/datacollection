for cas in xrange(1,1+input()):
    n = input()
    print "Case #%s:" % cas,
    if n == 0:
        print "INSOMNIA"
    else:
        s = set()
        v = 0
        while len(s) < 10:
            v += n
            s |= set(str(v))

        print v
