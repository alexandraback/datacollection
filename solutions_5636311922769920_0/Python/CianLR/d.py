T = int(raw_input())

for case in xrange(1, T+1):
    K, C, S = [int(x) for x in raw_input().split()]
    if K != S:
        raise NotImplementedError("K must equal S")

    checks = [str(x*(K**(C-1)) + 1) for x in xrange(S)]
    print 'Case #' + str(case) + ':', ' '.join(checks)
