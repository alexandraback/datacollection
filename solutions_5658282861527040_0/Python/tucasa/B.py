if __name__ == '__main__':
    T = input()
    for t in xrange(1, T + 1):
        A, B, K = map(int, raw_input().split())
        ret = 0
        for i in xrange(A):
            for j in xrange(B):
                if i & j < K:
                    ret += 1
        print 'Case #%d: %d' % (t, ret)