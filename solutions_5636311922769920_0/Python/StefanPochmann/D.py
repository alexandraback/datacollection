for x in range(1, input() + 1):
    K, C, S = map(int, raw_input().split())
    print 'Case #%d:' % x,
    if S * C < K:
        print 'IMPOSSIBLE'
    else:
        k = 0
        while k < K:
            i = 0
            for _ in range(min(C, K-k)):
                i = i * K + k
                k += 1
            print i + 1,
        print
