import sys


def offset(i, j):
    res = (i - 1) * (K ** C - K) // (K - 1) + j
    assert res <= K ** C
    print(K, C, i, j, res, file=sys.stderr)
    return res

NO = 'IMPOSSIBLE'
T = int(input())
for t in range(T):
    K, C, S = map(int, input().split())

    print("Case #{}:".format(t + 1), end=' ')
    if K == 1:
        print(1)
        continue

    if C == 1:
        if K != S:
            print(NO)
        else:
            print(' '.join([str(i + 1) for i in range(S)]))
    else:
        if 2 * S < K:
            print(NO)
        else:
            print(' '.join([str(offset(2 * i + 1, min(2 * i + 2, K)))
                            for i in range((K + 1) // 2)]))
