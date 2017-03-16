from math import sqrt

def eval(r, k):
    return 2 * k ** 2 + (2 * r + 3) * k + (2 * r + 1)

cases = input()
for i in xrange(1, cases + 1):
    r, t = [int(t) for t in raw_input().split()]
    deter = sqrt((2 * r + 3) ** 2 - 8 * (2*r + 1 - t))
    k = int((-(2 * r + 3) + deter) / 4.0)
    if eval(r, k) > t:
        print "Case #%d: %d" % (i, k)
    else:
        print "Case #%d: %d" % (i, k + 1)