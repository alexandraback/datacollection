def control(K, C, S):
    if 2 * S < K:
        return 'IMPOSSIBLE'
    if C == 1:
        if S < K:
            return 'IMPOSSIBLE'
        return ' '.join(map(str, range(1, K+1)))
    if K == 1:
        return 1
    result = []
    for i in xrange(0, K, 2):
        x = i*(K**(C-1)) + i + 2
        result.append(x if x < K**C else x-1)
    return ' '.join(map(str, result))

def main():
    T = int(raw_input())
    for i in xrange(1, T+1):
        K, C, S = map(int, raw_input().split())
        print 'Case #%d:' % i, control(K, C, S)

main()
