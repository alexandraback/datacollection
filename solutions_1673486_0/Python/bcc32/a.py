import sys, itertools

f = open(sys.argv[1])

t = int(f.readline())

def prob(p, perm):
    l = [0.0] * len(perm)
    for i in xrange(len(perm)):
        if perm[i]:
            l[i] = p[i]
        else:
            l[i] = 1.0 - p[i]
    return reduce(lambda x, y: x * y, l)

for _t in xrange(t):
    a, b = map(int, f.readline().split())
    p = map(float, f.readline().split())
    keep = 0.0
    back = [0.0] * a
    enter = 0.0
    for perm in itertools.product([True, False], repeat = a):
        probability = prob(p, perm)
        keep += probability * ((b + 1 - a) if all(perm) else (b + 1 - a) + (b + 1))
        for i in xrange(a):
            back[i] += probability * ((b + 1 - a + 2 * i + 2) if all(perm[:-i - 1]) else (b + 1 - a + 2 * i + 2 + b + 1))
        enter += probability * (1 if all(perm) and a == b else b + 2)
    print 'Case #%d: %f' % (_t + 1, min([keep] + back + [enter]))
