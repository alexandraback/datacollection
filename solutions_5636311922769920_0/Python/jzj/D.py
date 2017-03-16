def solve():
    k, c, s = map(int, raw_input().split())
    if k != s:
        raise Exception()

    delta = k ** (c - 1)
    return ' '.join([str(1 + i * delta) for i in xrange(k)])

T = int(raw_input())
for case_no in xrange(1, T + 1):
    print "Case #%d: %s" % (case_no, str(solve()))
