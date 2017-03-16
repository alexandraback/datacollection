import sys


def f(K, C, S):
    r = range(K)
    l = [0] * K
    for c in range(C):
        l = [K ** c * x + y for x, y in zip(r, l)]
    return ' '.join([str(i + 1) for i in l])

with open(sys.argv[1]) as fi:
    for i, n in enumerate(fi.readlines()[1:]):
        print "Case #%d:" % (i + 1), f(*map(int, n.split()))
