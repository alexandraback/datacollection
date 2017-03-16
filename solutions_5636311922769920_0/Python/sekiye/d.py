def solve(K, C, S):
    n = (K + C - 1) / C
    if n > S:
        return 'IMPOSSIBLE'
    v = []
    for i in xrange(n):
        begin = C * i
        end = min(K, C * (i + 1))
        cur = K ** (C - 1)
        sum = 1
        for j in range(begin, end):
            sum += cur * j
            cur /= K
        v.append(sum)
    return ' '.join(map(str, v))

T = int(raw_input())
for i in range(T):
    K, C, S = map(int, raw_input().split())
    print 'Case #%d:' % (i + 1), solve(K, C, S)
