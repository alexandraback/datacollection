from fractions import Fraction
import itertools
import sys
import gmpy

def sign(f):
    if f > 0:
        return 1
    elif f == 0:
        return 0
    else:
        return -1

def go(w, h, d, x, y):
    x = gmpy.mpq(x)
    y = gmpy.mpq(y)
    angles = set()
    four = list(itertools.product([x, 2 * w - x], [y, 2 * h - y]))
    for i in xrange(-55, 55):
        for j in xrange(-55, 55):
            for x1, y1 in four:
                x2, y2 = x1 + 2 * w * i, y1 + 2 * h * j
                if (x - x2) ** 2 + (y - y2) ** 2 <= d * d + 1e-9:
                    if x != x2:
                        angles.add((sign(x - x2), (y - y2) / (x - x2)))
                    else:
                        angles.add((sign(y - y2), "inf"))
    angles.remove((0, "inf"))
    return len(angles)

t = int(sys.stdin.readline())
for i in xrange(t):
    h, w, d = [int(s) for s in sys.stdin.readline().split()]
    for r in xrange(h):
        row = sys.stdin.readline().rstrip('\n')
        c = row.find('X')
        if c != -1:
            x, y = c, r
    print "Case #%d: %s" % (i + 1, go(w - 2, h - 2, d, x - 0.5, y - 0.5))
    sys.stdout.flush()
