def res(a, b, c):
    return a + b + a + b - 4

t = int(input())
for cy in range(t):
    n, m, k = [int(i) for i in input().split()]
    r = float("inf")
    for i in range(1, k + 1):
        b, c = k // i, k % i
        a = i
        if (a <= n and b + min(c, 1) <= m) or (a <= m and b + min(c, 1) <= n):
            r = min(r, res(a, b, c))
    print("Case #", cy + 1, ": ", r, sep="")