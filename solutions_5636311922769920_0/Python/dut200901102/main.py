for _ in xrange(input()):
    print "Case #%d:" % (_ + 1),
    K, C, S = map(int, raw_input().split())
    print ' '.join(map(str, range(1, S + 1)))