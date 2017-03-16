def f(r, n):
    return n * (2 * (r + n) - 1)

T = int(input())
for tc in range(T):
    r, t = map(int, input().split())
    l = -1
    h = 10**11
    while l + 1 < h:
        m = (l + h) // 2
        if f(r, m) > t:
            h = m
        else:
            l = m
    assert f(r, l) <= t and f(r, h) > t
    print("Case #{}: {}".format(tc + 1, l))
