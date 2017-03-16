def yoba(a, m, curr=0, best=None):

    if best and curr >= best:
        return best

    while m and m[0] < a:
        a = a + m[0]
        m = m[1:]

    if len(m) == 0:
        return curr

    best = yoba(a, m[1:], curr + 1, best)
    if a > 1:
        best = yoba(2 * a - 1, m, curr + 1, best)
    return best

for i in range(int(input())):
    a, n = tuple(map(int, input().split()))
    m = sorted(map(int, input().split()))

    print("Case #{}: {}".format(i + 1, yoba(a, m)))
