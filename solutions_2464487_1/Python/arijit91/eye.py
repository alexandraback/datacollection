t = int(raw_input())

def f(r, n):
    a = 2 * r + 1
    d = 4
    return (n * (2 * a + (n - 1) * d)) / 2

for cas in range(1, t+1):
    r, t = [int(x) for x in raw_input().split(' ')]

    lo = 0
    ans = 0
    hi = 10 ** 20

    while lo <= hi :
        mid = (lo + hi) / 2

        if f(r, mid) <= t :
            ans = mid
            lo = mid + 1
        else :
            hi = mid - 1

    assert ans >= 1

    print "Case #" + str(cas) + ": " + str(ans)
