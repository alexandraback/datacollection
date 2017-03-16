T = int(input())
for ind in xrange(1, T+1):
    N = int(input())
    if N == 0:
        print "Case #%d: INSOMNIA" % ind
        continue
    digits = set(str(N))
    ct = 1
    temp = N
    while len(digits) < 10:
        ct += 1
        temp = N*ct
        digits.update(str(temp))
    print "Case #%d: %d" % (ind, temp)
