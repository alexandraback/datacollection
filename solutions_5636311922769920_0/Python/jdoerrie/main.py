T = int(input())
for t in range(T):
    K, C, S = map(int, input().split())
    print("Case #{}: {}".format(
        t + 1, ' '.join([str((i + 1) * K ** (C - 1)) for i in range(K)])))
