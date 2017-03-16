if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        N, M, K = [int(s) for s in raw_input().split()]

        best = K
        for k in xrange(0, 2 ** (N*M) + 1):
            m = [['.' for x in xrange(M)] for y in xrange(N)]
            cnt = 0
            for i in xrange(0, M*N):
                if k & 2**i == 2**i:
                    x = i % M
                    y = i / M
                    m[y][x] = '*'
                    cnt += 1

            if cnt > best:
                break

            enclosed = 0
            for y in xrange(0, N):
                for x in xrange(0, M):
                    if m[y][x] == '*':
                        enclosed += 1
                    elif ((y == 0 or m[y - 1][x] == '*') and
                            (y == N - 1 or m[y + 1][x] == '*') and
                            (x == 0 or m[y][x - 1] == '*') and
                            (x == M - 1 or m[y][x + 1] == '*')):
                            enclosed += 1

            if enclosed >= K:
                best = min(best, cnt)

        print 'Case #%d: %d' % (caseno + 1, best)
