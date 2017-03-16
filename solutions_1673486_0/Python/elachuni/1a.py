from operator import mul

#f = open('1a.in')
f = open('A-small-attempt0.in')
T = int(f.readline().strip())

mult = lambda a: reduce(mul, a, 1)

for case in range(T):
    A, B = [int(x) for x in f.readline().strip().split()]
    ps = [float(x) for x in f.readline().strip().split()]
    remaining = B - A
    es = []
    p0 = mult(ps)
    es.append(p0 * (remaining + 1) + (1 - p0) * (remaining + B + 2))
    for i in range(1, len(ps)):
        pi = mult(ps[:-i])
        es.append(pi * (2 * i + remaining + 1) +
                 (1 - pi) * (2 * i + remaining + B + 2))
    es.append(2 + B)
    print "Case #%d: %f" % (case + 1, min(es))
