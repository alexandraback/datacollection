import sys

def calc(K, C, S):
    if C * S < K:
        return 'IMPOSSIBLE'

    def convert(digits):
        return 1 + reduce(lambda x, y: K * x + y, digits)

    return ' '.join(map(str, (convert(xrange(d0, min(K, d0 + C))) for d0 in xrange(0, K, C))))

T = int(sys.stdin.readline())
for i in xrange(T):
    K, C, S = map(int, sys.stdin.readline().split())
    print 'Case #%d: %s' % (i + 1, calc(K, C, S))
