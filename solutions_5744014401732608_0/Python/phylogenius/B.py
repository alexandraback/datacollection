from math import floor, log

for T in range(1, int(input()) + 1):
    B, M = map(int, input().strip().split())
    if 2 ** (B - 2) < M:
        print('Case #{}: IMPOSSIBLE'.format(T))
    else:
        print('Case #{}: POSSIBLE'.format(T))
        A = [[0] * B for _ in range(B)]
        for i in range(B):
            for j in range(i+1, B):
                A[i][j] = 1
        N = 2 ** (B - 2) - M
        while N:
            x = floor(log(N, 2))
            A[0][B - (x + 1)] = 0
            N -= 2 ** x
        # d = floor(log(M, 2))
        # A = [[0] * B for _ in range(B)]
        # dp = d + 2
        # for i in range(dp):
        #     for j in range(i+1, dp):
        #         A[i][j] = 1
        # M -= 2 ** d
        # i = dp
        # while M:
        #     print('M', M)
        #     print('i', i)
        #     x = floor(log(M, 2))
        #     A[0][i] = 1
        #     A[i][d - x] = 1
        #     M -= 2 ** x
        #     i += 1
        # for i in range(B):
        #     A[i][B-1], A[i][dp - 1] = A[i][dp - 1], A[i][B-1]
        print('\n'.join(' '.join(map(str, x)) for x in A))