from collections import defaultdict

digits = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")

dm = [
    ('Z', 0),
    ('W', 2),
    ('U', 4),
    ('X', 6),
    ('G', 8),

    ('R', 3),
    ('S', 7),
    ('O', 1),
    ('V', 5),
    ('N', 9),
]

def main():
    T = int(raw_input())
    for i in xrange(T):
        S = raw_input()
        d = defaultdict(int)
        for c in S:
            d[c] += 1
        ret = []
        for c, n in dm:
            # print d, c, n, ret
            while c in d:
                if d[c] <= 0:
                    del d[c]
                    continue
                ret.append(n)
                for cc in digits[n]:
                    d[cc] -= 1
        output(i, ret)


def output(casenum, ret):
    print 'Case #%d: %s' % (casenum + 1, ''.join(map(str, sorted(ret))))


main()
