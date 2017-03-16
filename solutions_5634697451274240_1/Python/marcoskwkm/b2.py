T = int(raw_input())
for t in xrange(1, T + 1):
    seq, has1, ans = raw_input(), 0, 0
    for i in xrange(len(seq)):
        if seq[i] == '+':
            has1 = 1
            continue
        if i + 1 < len(seq) and seq[i + 1] == '-': continue
        ans += 1 + has1
        has1 = 0
    print "Case #%d: %d" % (t, ans)
