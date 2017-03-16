import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        D = int(f.readline())
        P = map(int, f.readline().split())

        pmax = max(P)

        best = pmax
        for i in xrange(1, pmax+1):
            num_special = 0
            for p in P:
                num_special += (p + i - 1) // i - 1
            best = min(best, i + num_special)

        print "Case #%d: %d" % (_T + 1, best)
