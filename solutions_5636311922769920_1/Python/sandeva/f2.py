import sys


def f(K, C, S):
    k = range(K)
    C = min(K, C)
    m = [K ** i for i in range(C)]
    m.reverse()
    n = (K - 1) / C + 1
    if S < n:
        return ['IMPOSSIBLE']
    return [str(1 + sum([x * y for x, y in zip(m, k[i * C: (i + 1) * C])]))
            for i in range(n)]

with open(sys.argv[1]) as fi:
    for i, n in enumerate(fi.readlines()[1:]):
        print "Case #%d:" % (i + 1), ' '.join(f(*map(int, n.split())))
