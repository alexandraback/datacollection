def bs(a, x, ll=0, rr=None):
    if rr is None:
        rr = len(a)
    while ll < rr:
        c = (ll+rr)//2
        cval = a[c]
        if abs(cval - x) < abs(a[ll] - x):
            ll = c+1
        else: 
            rr = c
    if a[c] < x and c + 1 < len(a):
        c += 1
        assert a[c] > x
    if a[c] < x:
        c = 0
    return c


def sol(A, B, n):
    A.sort()
    B.sort()
    BB = B[::1]
    c1 = 0
    l = 0
    for x in A:
        while l < n and B[l] < x:
            l += 1
            c1 += 1
        if l == n:
            break
        l += 1

    c2 = 0
    AA = A[::1]
    BB = B[::1]
    l, r = 0, n-1
    ll, rr = 0, n - 1
    while l <= r:
        while ll <= rr and l <= r and A[l] > B[ll]:
            l += 1
            ll += 1
            c2 += 1
        l += 1
        rr -= 1
    return c2, c1


import sys
readline = sys.stdin.readline

tn = int(readline())
for i in xrange(1, tn + 1):
    N = int(readline())
    A = map(float, readline().split(" "))
    B = map(float, readline().split(" "))
    assert N == len(A) == len(B)
    print 'Case #{}: {} {}'.format(i, *(sol(A, B, N)))

