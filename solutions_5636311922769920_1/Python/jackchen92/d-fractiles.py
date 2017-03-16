T = int(raw_input())
for t in xrange(1, T+1):
    K,C,S = [int(tok) for tok in raw_input().split()]
    clean = []
    cur = 0
    lev = 0
    for i in range(K):
        cur += i * K ** lev
        lev += 1
        if lev == C or i == K-1:
            clean.append(cur)
            lev = 0
            cur = 0
    print 'Case #%d:' % t,
    if len(clean) <= S:
        print ' '.join([str(x+1) for x in clean])
    else:
        print 'IMPOSSIBLE'
