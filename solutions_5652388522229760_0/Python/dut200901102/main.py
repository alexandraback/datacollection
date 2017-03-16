for _ in xrange(input()):
    print "Case #%d:" % (_ + 1),
    n = input()
    if n == 0:
        print "INSOMNIA"
        continue
    s = set()
    cur = 0
    while len(s) < 10:
        cur += n
        for ch in str(cur):
            s.add(ch)
    print cur