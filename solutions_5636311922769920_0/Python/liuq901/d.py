def solve(K, C, S):
    imp = 'IMPOSSIBLE'
    if C == 1:
        if K == S:
            return ' '.join(map(str, xrange(1, K + 1)))
        else:
            return imp
    n = (K + 1) / 2
    if S < n:
        return imp
    res = []
    offset = K ** (C - 1)
    for i in xrange(n):
        res.append(offset * i * 2 + (i + 1) * 2)
    if K % 2 == 1:
        res[-1] -= 1
    return ' '.join(map(str, res))

T = int(raw_input())
for t in xrange(T):
    K, C, S = map(int, raw_input().split())
    print 'Case #%d: %s' % (t + 1, solve(K, C ,S))
