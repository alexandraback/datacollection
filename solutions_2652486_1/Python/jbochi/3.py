import itertools
from collections import defaultdict

def cards(m):
    return range(2, m + 1)

def combinations(c, n):
    return itertools.combinations_with_replacement(c, n)

def select(n):
    return itertools.product([True, False], repeat=n)

def choices(m, n):
    for cs in combinations(cards(m), n):
        products = defaultdict(int)
        for ss in select(n):
            p = reduce(lambda a, b: a * b, (c for c, s in zip(cs, ss) if s), 1)
            products[p] += 1
        yield cs, products

def most_possible(products, choices):
    bestt = 0
    best = None
    for c, pp in choices:
        total = 0
        impossible = False
        for p in products:
            t = pp[p]
            if t == 0:
                impossible = True
                break
            total += t
        if not impossible and total > bestt:
            bestt = total
            best = c
    return best

def solve():
    with open("3.in") as f:
        c = [map(int, l.strip().split()) for l in f.readlines()]
    for t in range(c[0][0]):
        R, N, M, K = c[1]
        print "Case #%d:" % (t + 1)
        #C = list(choices(M, N))
        import pickle;
        with open("C2", "r") as f:
            C = pickle.load(f)

        for i in xrange(R):
            best = most_possible(c[i+2], C)
            best = best or [2 for i in range(K)]
            print ''.join(map(str, best))

if __name__ == "__main__":
    solve()
