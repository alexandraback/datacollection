import math

def rotations(n):
    results = []

    expn = int(math.log(n, 10))
    exp = 10 ** expn

    for _ in xrange(0, expn):
        n, r = divmod(n, 10)
        n += r * exp
        results.append(n)

    return frozenset(results)


def n_rotations(a, b):
    results = set()
    for i in xrange(a, b):
        for j in rotations(i):
            if a <= j <= b and i != j:
                results.add(frozenset([i, j]))
    return len(results)

for i in xrange(1, int(raw_input()) + 1):
    x, y = [ int(j) for j in raw_input().split(" ") ]
    print "Case #{0}: {1}".format(i, n_rotations(x, y))
