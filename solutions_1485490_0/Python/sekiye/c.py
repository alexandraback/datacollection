def solve():
    N, M = map(int, raw_input().split())
    A_ = map(int, raw_input().split())
    A = []
    for i in xrange(N):
        A.append((A_[2 * i], A_[2 * i + 1]))
    B_ = map(int, raw_input().split())
    B = []
    for i in xrange(M):
        B.append((B_[2 * i], B_[2 * i + 1]))
    if N == 3 and A[0][1] == A[1][1] == A[2][1]:
        A[0] = (A[0][0] + A[1][0] + A[2][0], A[0][1])
        N = 1
    elif N >= 2 and A[0][1] == A[1][1]:
        A[0] = (A[0][0] + A[1][0], A[0][1])
        A[1] = A[2]
        N = 2
    elif N == 3 and A[1][1] == A[2][1]:
        A[1] = (A[1][0] + A[2][0], A[1][1])
        N = 2
    ans = 0
    for i in xrange(M + 1):
        for j in xrange(i, M + 1):
            total = 0
            sum_ = 0
            for k in xrange(i):
                if A[0][1] == B[k][1]:
                    sum_ += B[k][0]
            total += min(A[0][0], sum_)
            if N > 1:
                sum_ = 0
                for k in xrange(i, j):
                    if A[1][1] == B[k][1]:
                        sum_ += B[k][0]
                total += min(A[1][0], sum_)
            if N > 2:
                sum_ = 0
                for k in xrange(j, M):
                    if A[2][1] == B[k][1]:
                        sum_ += B[k][0]
                total += min(A[2][0], sum_)
            ans = max(ans, total)
    if N == 3 and A[0][1] == A[2][1]:
        sum_ = 0
        for k in xrange(i):
            if A[0][1] == B[k][1]:
                sum_ += B[k][0]
        total = min(A[0][0] + A[2][0], sum_)
        ans = max(ans, total)
    return ans

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
