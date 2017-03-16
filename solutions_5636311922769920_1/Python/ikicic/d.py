T = int(input())
for t in range(1, T + 1):
    K, C, S = [int(x) for x in input().split()]

    out = []
    k = 0
    while k < K:
        pos = 0
        for depth in range(C):
            pos = pos * K + min(k, K - 1)
            k += 1
        out.append(pos)

    if len(out) <= S:
        print("Case #{}: {}".format(t, " ".join(str(x + 1) for x in out)))
    else:
        print("Case #{}: IMPOSSIBLE".format(t))
