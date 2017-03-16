import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        X, R, C = map(int, f.readline().split())

        # 1xX doesn't fit
        if X > R and X > C:
            print "Case #%d: RICHARD" % (_T + 1,)
            continue

        # X/2 x X/2 'L' doesn't fit
        if X > 2 * min(R, C):
            print "Case #%d: RICHARD" % (_T + 1,)
            continue

        # not even
        if (R * C) % X != 0:
            print "Case #%d: RICHARD" % (_T + 1,)
            continue

        # trap hole
        if X >= 7:
            print "Case #%d: RICHARD" % (_T + 1,)
            continue

        # always fits
        if X <= 2:
            print "Case #%d: GABRIEL" % (_T + 1,)
            continue

        assert min(R, C) > 1

        if X % min(R, C) == 0 and X > min(R, C):
            print "Case #%d: RICHARD" % (_T + 1,)
            continue

        if min(R, C) == 2:
            assert X <= 4

            if X == 3:
                assert R * C >= 6
                print "Case #%d: GABRIEL" % (_T + 1,)
                continue

            assert R * C >= 8, (X, R, C)

            if X == 4 and (R * C == 8):
                print "Case #%d: RICHARD" % (_T + 1,)
                continue

            if X == 4 and (R * C >= 12):
                print "Case #%d: GABRIEL" % (_T + 1,)
                continue

            assert 0, (X, R, C)

        print >>sys.stderr, "not sure:", X, R, C
        print "Case #%d: GABRIEL" % (_T + 1,)
        continue

