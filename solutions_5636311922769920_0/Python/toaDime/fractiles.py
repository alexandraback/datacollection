def main_code(x):
    K, C, S = tuple(map(int, input().split()))
    if S < K - C + 1:
        print("Case #" + str(x + 1) + ":", "IMPOSSIBLE")
    else:
        a = 0
        b = 1
        for _ in range(1, C):
            a = K * (a + b - 1)
            b = b + 1
            if b > K:
                b = K
        needed = list(range(a + b, a + K + 1))
        print("Case #" + str(x + 1) + ":", *needed)

T = int(input())
for x in range(T):
    main_code(x)
