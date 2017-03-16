T = int(raw_input())

for case_ in xrange(T):
    (k, c, s) = map(int, raw_input().split())
    print "Case #%d:" % (case_ + 1),
    print ' '.join(map(str, range(1, s + 1)))
