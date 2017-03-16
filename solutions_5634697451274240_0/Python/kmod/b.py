import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        s = f.readline().strip()

        cur = '+'
        ans = 0
        for c in reversed(s):
            if c != cur:
                ans += 1
            cur = c

        print "Case #%d: %s" % (_T + 1, ans)
