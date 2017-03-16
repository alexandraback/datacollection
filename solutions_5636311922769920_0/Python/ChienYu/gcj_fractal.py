from sys import stdin

def each_case(K, C, S):
    if C * S < K:
        return 'IMPOSSIBLE'

    positions = []
    for i in xrange(K/C):
        p = 0
        for c in xrange(i*C, (i+1)*C):
            p = p * K + c
        positions.append(p+1)
    if K%C:
        p = 0
        for c in xrange((K/C)*C, K):
            p = p * K + c
        positions.append(p+1)
    assert len(positions) <= S

    return ' '.join(map(str, positions))

T = int(stdin.readline())
for t in xrange(1,T+1):
    K, C, S = map(int, stdin.readline().split())
    print 'Case #{}: {}'.format(t, each_case(K, C, S))
