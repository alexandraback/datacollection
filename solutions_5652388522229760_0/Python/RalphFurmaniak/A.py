T = int(input())
for tc in xrange(1,T+1):
    digits = set()
    N = int(input())
    if N == 0:
        print "Case #%s: INSOMNIA" % tc
    else:
        cur = 0
        while len(digits)<10:
            cur += N
            digits = digits | set(str(cur))
        print "Case #%s: %s" % (tc, cur)
