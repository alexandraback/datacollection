def asum_even(n):
    assert n % 2 == 0
    n /= 2
    r = 2 * n * (n+1) * (2*n + 1)
    assert r % 3 == 0
    return r / 3

def asum_odd(n):
    assert n % 2 == 1
    n = (n + 1) / 2
    r = n * (4 * n * n - 1)
    assert r % 3 == 0
    return r / 3

def asum(n):
    if n % 2 == 0:
        return asum_even(n)
    else:
        return asum_odd(n)

def area(r, k):
    return asum(r-1+2*k) - asum(r-1) - (asum(r-2 + 2*k) - asum(r-2))

TT = int(raw_input().strip())
for T in range(TT):
    r, t = [int(x) for x in raw_input().strip().split()]
    kmin = 1
    kmax = int(1e18)
    while kmax > kmin:
        k = (kmin + kmax + 1) / 2
        a = area(r, k)
        if a > t:
            kmax = k-1
        elif a < t:
            kmin = k
        else:
            kmin = kmax = k
    print "Case #%d: %d" % (T+1, kmin)
    
