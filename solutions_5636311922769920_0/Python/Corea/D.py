T = int(raw_input())
for i in xrange(1, T+1):
    K, C, S = map(int, raw_input().split())
    print 'Case #%d:' % i,
    if C * S < K:
        print 'IMPOSSIBLE'
    else:
        now = 0
        for i in xrange(K):
            if i % C == 0 and i != 0:
                print now + 1,
                now = 0
            now *= K
            now += i
        print now + 1
