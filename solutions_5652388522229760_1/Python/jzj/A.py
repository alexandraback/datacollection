def solve():
    n = int(raw_input())
    if n == 0:
        return "INSOMNIA"
    s = set()
    cur = 0
    while len(s) < 10:
        cur += n
        for c in str(cur):
            s.add(c)
    return cur

T = int(raw_input())
for case_no in xrange(1, T + 1):
    print "Case #%d: %s" % (case_no, str(solve()))
