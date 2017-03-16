from sets import Set

for tc in xrange(input()):
    digits = Set(['0','1','2','3','4','5','6','7','8','9'])
    N = int(raw_input())
    if N == 0:
        print "Case #%d: INSOMNIA" % (tc + 1)
        continue
    for i in xrange(N,100*N+1,N):
        strN = str(i)
        for j in strN:
            digits.discard(j)
        if len(digits) == 0:
            break
    if len(digits) == 0:
        print "Case #%d: %d" % (tc + 1, i)
    else:
        print "Case #%d: INSOMNIA" % (tc + 1)
