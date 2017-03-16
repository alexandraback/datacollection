import sys

def solve(_T, X, R, C):
    # 1xX doesn't fit
    if X > R and X > C:
        print "Case #%d: RICHARD" % (_T + 1,)
        return

    # X/2 x X/2 'L' doesn't fit
    if X > 2 * min(R, C):
        print "Case #%d: RICHARD" % (_T + 1,)
        return

    # not even
    if (R * C) % X != 0:
        print "Case #%d: RICHARD" % (_T + 1,)
        return

    # trap hole
    if X >= 7:
        print "Case #%d: RICHARD" % (_T + 1,)
        return

    # always fits
    if X <= 2:
        print "Case #%d: GABRIEL" % (_T + 1,)
        return

    assert min(R, C) > 1

    if X % min(R, C) == 0 and X > min(R, C):
        print "Case #%d: RICHARD" % (_T + 1,)
        return

    if min(R, C) == 2:
        assert X <= 4

        if X == 3:
            assert R * C >= 6
            print "Case #%d: GABRIEL" % (_T + 1,)
            return

        assert R * C >= 8, (X, R, C)

        if X == 4 and (R * C == 8):
            print "Case #%d: RICHARD" % (_T + 1,)
            return

        if X == 4 and (R * C >= 12):
            print "Case #%d: GABRIEL" % (_T + 1,)
            return

        assert 0, (X, R, C)

    if max(R, C) >= X + 2 and min(R, C) >= (X + 1)//2 + 2:
        print "Case #%d: GABRIEL" % (_T + 1,)
        return

    if X == 3 and R >= 3 and C >= 3:
        print "Case #%d: GABRIEL" % (_T + 1,)
        return

    if X == 4 and min(R, C) >= 3 and max(R, C) >= 4:
        print "Case #%d: GABRIEL" % (_T + 1,)
        return

    # 'w' shape needs (1 + 9) on one side and (3 + 12) on the other
    if X == 5 and min(R, C) == 3 and max(R, C) < 10:
        print "Case #%d: RICHARD" % (_T + 1,)
        return

    if X == 5 and min(R, C) == 3 and max(R, C) >= 10:
        print "Case #%d: RICHARD" % (_T + 1,)
        return
    if X == 5 and min(R, C) >= 4 and max(R, C) >= 5:
        print "Case #%d: GABRIEL" % (_T + 1,)
        return

    if X == 6 and min(R, C) >= 4 and max(R, C) >= 6:
        print "Case #%d: GABRIEL" % (_T + 1,)
        return

    print >>sys.stderr, "not sure:", X, R, C
    assert 0, (X, R, C)


if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    # for x in xrange(1, 7):
        # for r in xrange(1, 21):
            # for c in xrange(r, 21):
                # solve(0, x, r, c)

    T = int(f.readline())
    for _T in xrange(T):
        X, R, C = map(int, f.readline().split())
        solve(_T, X, R, C)

