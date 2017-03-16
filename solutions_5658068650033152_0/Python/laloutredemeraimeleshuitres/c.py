def solve(N, M, K):
    if M > N:
        return solve(M, N, K)
    if K <= 4:
        return K
    if M <= 2:
        return K
    if K in [5, 6, 7]:
        return K-1
    if K == 8:
        if M >= 4:
            return 6
        else:
            return 7
    if K == 9:
        if M >= 4:
            return 7
        else:
            return 8
    if M == 3:
        if K <= (M*N-4):
            for i in range(10):
                if 3*i+2 >= K:
                    return 2*i+2
        return 2*N+2 - (M*N-K)
    if K in [10,11,12]:
        return 8
    if N == 4:
        return min(12, 8+K-12)
    if N != 5:
        print N, M, K
        assert(0)
    if K == 13:
        return 9
    if K in [14,15,16]:
        return 10
    return min(14, 10+K-16)
        

T = input()
for i in range(T):
    N, M, K = map(int, raw_input().split())
    print "Case #{}: {}".format(i+1, solve(N, M, K))
