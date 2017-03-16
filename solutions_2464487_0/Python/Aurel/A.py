from math import sqrt

def ok(r, t, n):
    used = n * (2*r-1+2*n)
    return used <= t

T = int(raw_input())
for tcase in xrange(T):
    r, t = map(long,raw_input().split())

    delta = 4 * r * r + 1 - 4 * r + 8 * t
    x = ((1 - 2 * r) + sqrt(delta)) / 4
    res = long(x)
    
    # Because of rounding we might be off. Try to lower
    while not ok(r, t, res):
        res = res - 1
    # Try to increase
    while ok(r, t, res+1):
        res = res + 1

    print "Case #{:d}: {:d}".format(tcase+1, res)
