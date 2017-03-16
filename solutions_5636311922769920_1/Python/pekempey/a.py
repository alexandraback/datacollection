def solve(K, C, S):
    result = []

    p = (K ** (C - 1) - 1) // (K - 1) * K if K > 1 else C - 1

    for i in range(0, K, C):
        k = i
        for j in range(C - 1):
            k = k * K + K + min(K - 1, i + j + 1)
        result.append(k + 1 - p)

    if len(result) > S:
        result = []
    return result

T = int(input())

for i in range(T):
    K, C, S = map(int, input().split())
    ans = solve(K, C, S)

    print("Case #{0}: ".format(i + 1), end = "")

    if len(ans) == 0:
        print("IMPOSSIBLE")
    else:
        print(*ans)