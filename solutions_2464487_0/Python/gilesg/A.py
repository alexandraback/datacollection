from math import pi
def ints():
    return map(int, raw_input().split())

num_cases, = ints()

def paint(r, k):
    return k * (2 * r + 2 * k - 1)

for case_num in xrange(1, num_cases + 1):
    r, t = ints()
    lo = 0
    hi = 10 ** 19
    while lo < hi:
        mid = (lo + hi) / 2
        p = paint(r, mid)
        if p > t:
            hi = mid
        else:
            lo = mid + 1

    print "Case #%d: %s" % (case_num, lo-1)
