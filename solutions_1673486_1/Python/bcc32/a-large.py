import sys

f = open(sys.argv[1])

t = int(f.readline())

product = lambda l: reduce(lambda x, y: x * y, l, 1)

for _t in xrange(t):
    a, b = map(int, f.readline().split())
    p = map(float, f.readline().split())
    prob = product(p)
    keep = prob * (b - a + 1) + (1 - prob) * (b - a + 1 + b + 1)
    back = [0.0] * a
    for i in xrange(a - 1, -1, -1):
        pro = 1.0
        back[i] = pro * (b - 1 + 1 + 2 * i + 2) + (1 - pro) * (b - a + 1 + 2 * i + 2 + b + 1)
        pro *= p[i]
    if a == b:
        enter = prob * 1 + (1 - prob) * (b + 2)
    else:
        enter = b + 2
    print 'Case #%d: %f' % (_t + 1, min([keep] + back + [enter]))
