import sys

divs = []


def divisor(n):
    if n <= 1:
        return 1
    if n <= 3:
        return False
    if not n % 2:
        return 2
    if not n % 3:
        return 3
    i, h = 5, 100  # n ** 0.5
    while i < h:
        if not n % i:
            return i
        if not n % (i + 2):
            return i + 2
        i += 6
    return False


def chk(l):
    r = []
    for d in divs:
        v = sum([v for v, b in zip(d, l) if b])
        d = divisor(v)
        if not d:
            return False
        r.append((v, d))
    return r


def f(N, J):
    for x in range(2, 11):
        divs.append([x ** y for y in range(N)])
    n = N - 2
    r = 1 << n
    rng = [1 << x for x in range(n)]
    j = 0
    for i in xrange(r):
        v = [True] + [bool(x & i) for x in rng] + [True]
        c = chk(v)
        if c:
            print c[-1][0],
            for _, cc in c:
                print cc,
            print
            j += 1
            if j == J:
                return

print "Case #1:"
with open(sys.argv[1]) as fi:
    f(*map(int, fi.readlines()[-1].split()))
