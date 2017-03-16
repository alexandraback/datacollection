dp = {}
dp2 = {}

def bruteForce(N, M, K, last):
    if (N, M, K, last) in dp:
        return dp[(N, M, K, last)]

    if N == 0:
        dp[(N, M, K, last)] = float("inf")
        return float("inf")

    if K <= last:
        dp[(N, M, K, last)] = last
        return last

    best = float("inf")
    if last == 0:
        for a in range(1, M - 2):
            best = min(bruteForce(N - 1, M, K - 2 * a - 2, a) + a + 2, best)
    else:
        for a in range(1, M - 2):
            if a < last:
                best = min(bruteForce(N - 1, M, K - last, last) + last - a, best)
            else:
                best = min(bruteForce(N - 1, M, K + last - 2 * a - 2, a) + a - last + 2, best)

    dp[(N, M, K, last)] = best
    return best
            

def solve(N, M, K):
    if (N, M, K) in dp2:
        return dp2[(N, M, K)]

    if N > M:
        N, M = M, N

    if N <= 2:
        dp2[(N, M, K)] = K 
        return K

    best = K
    # dp = {}
    
    for r in range(3, N + 1):
        for c in range(3, M + 1):
            if r * c - 4 >= K:
                best = min(best, 2 * (r + c - 2))

    best = min(best, bruteForce(N, M, K, 0))

    for k in range(5, K):
        best = min(best, solve(N, M, k) + K - k)

    for k in range(1, K):
        if solve(N, M, k) + solve(N, M, K - k) <= N * M:
            best = min(best, solve(N, M, k) + solve(N, M, K - k))

    dp2[(N, M, K)] = best
    return best


T = int(input())

for tc in range(1, T + 1):
    N, M, K = map(int, input().split())

    print("Case #{}: {}".format(tc, solve(N, M, K)))
