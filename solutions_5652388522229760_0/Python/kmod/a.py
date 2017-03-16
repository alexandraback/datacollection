import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N = int(f.readline())

        if N == 0:
            ans = "INSOMNIA"
        else:
            s = set()

            t = N
            i = 1
            while True:
                s.update(set(str(t)))
                if len(s) == 10:
                    break

                i += 1
                t += N

            ans = t

        print "Case #%d: %s" % (_T + 1, ans)
