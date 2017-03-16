T = int(raw_input())
for t in xrange(T):
    K, C, S = map(int, raw_input().split())
    assert K == S
    print 'Case #{}: {}'.format(t + 1, ' '.join(str(i + 1) for i in xrange(S)))
