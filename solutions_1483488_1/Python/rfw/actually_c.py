import math
import multiprocessing
import functools

def rotations(n):
    results = []

    expn = int(math.log(n, 10))
    exp = 10 ** expn

    for _ in xrange(0, expn):
        n, r = divmod(n, 10)
        n += r * exp
        results.append(n)

    return frozenset(results)

def n_rotations(p, a, b):
    results = set()
    for r in p.map(functools.partial(rots_for, a, b), xrange(a, b)):
        results |= r
    return len(results)

def rots_for(a, b, n):
    results = set()
    for m in rotations(n):
        if a <= m <= b and n != m:
            results.add(frozenset([n, m]))
    return results

if __name__ == "__main__":
    p = multiprocessing.Pool(20)

    for i in xrange(1, int(raw_input()) + 1):
        x, y = [ int(j) for j in raw_input().split(" ") ]
        print "Case #{0}: {1}".format(i, n_rotations(p, x, y))

