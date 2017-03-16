read_ints = lambda: map(int, raw_input().split())
T = int(raw_input())
INF = 1999999999

for no_t in xrange(1, T + 1):
    N, M = read_ints()
    A = [read_ints() for _ in xrange(N)]
    B = [[INF]*M for _ in xrange(N)]

    for i in xrange(N):
        mn = max(A[i])
        for j in xrange(M):
            B[i][j] = min(B[i][j], mn)

    for j in xrange(M):
        mn = max(A[i][j] for i in xrange(N))
        for i in xrange(N):
            B[i][j] = min(B[i][j], mn)

    print 'Case #%d: %s' % (no_t, 'YES' if A == B else 'NO')
