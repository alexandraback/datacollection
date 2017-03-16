T = int(raw_input())

for t in xrange(1, T + 1):
    A, B, K = map(int, raw_input().strip().split())
    cnt = (A + B - K) * K
    for a in xrange(K, A):
        for b in xrange(K, B):
            if a & b < K:
                cnt += 1
    print 'Case #%d: %d' % (t, cnt)
