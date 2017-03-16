import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        K, C, S = map(int, f.readline().split())

        if K > C * S:
            ans = "IMPOSSIBLE"
        else:
            s = set()

            def index(l):
                assert len(l) == C
                t = 0
                for i in xrange(len(l)):
                    if l[i] >= K:
                        l[i] = 0
                    t += l[i] * (K ** i)
                return t + 1

            num_needed = (K + C - 1) / C
            assert num_needed <= S
            ans = ""
            for i in xrange(num_needed):
                if ans:
                    ans += " "
                ans += str(index(range(i * C, (i + 1) * C)))

        print "Case #%d: %s" % (_T + 1, ans)
