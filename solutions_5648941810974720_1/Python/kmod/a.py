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

        d = {}
        for c in s:
            d[c] = d.get(c, 0) + 1

        r = [0] * 10

        def find(c, n, s):
            while d.get(c, 0):
                r[n] += 1
                for _c in s:
                    d[_c] -= 1
                    if d[_c] == 0:
                        del d[_c]

        find('Z', 0, "ZERO")
        find('X', 6, "SIX")
        find('W', 2, "TWO")
        find('U', 4, "FOUR")
        find('F', 5, "FIVE")
        find('V', 7, "SEVEN")
        find('O', 1, "ONE")
        find('N', 9, "NINE")
        find('G', 8, "EIGHT")
        find('R', 3, "THREE")
        assert not d

        s = ""
        for i in xrange(10):
            for j in xrange(r[i]):
                s += str(i)

        print "Case #%d: %s" % (_T + 1, s)
