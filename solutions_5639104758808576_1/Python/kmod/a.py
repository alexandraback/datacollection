import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        smax, s = f.readline().split()
        smax = int(smax)
        assert smax + 1 == len(s)

        invited = 0
        num_standing = 0

        for i, c in enumerate(s):
            while num_standing < i:
                invited += 1
                num_standing += 1

            num_standing += int(c)

        print "Case #%d: %d" % (_T + 1, invited)
