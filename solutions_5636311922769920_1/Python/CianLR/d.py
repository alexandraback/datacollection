T = int(raw_input())

for case in xrange(1, T+1):
    K, C, S = [int(x) for x in raw_input().split()]
    if S < K/2.0:
        print 'Case #' + str(case) + ': IMPOSSIBLE'
        continue

    if C == 1:
        if S < K:
            print 'Case #' + str(case) + ': IMPOSSIBLE'
        else:
            checks = [str(x) for x in xrange(1, K+1)]
            print 'Case #' + str(case) + ':', ' '.join(checks)
        continue
    
    checks = [str(x*(K**(C-1)) + x + 2) for x in xrange(0, K, 2)]
    if K%2 == 1:
        checks[-1] =str(int(checks[-1]) - 1)
    print 'Case #' + str(case) + ':', ' '.join(checks)
