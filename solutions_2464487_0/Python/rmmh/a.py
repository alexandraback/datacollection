def to_ints(s):
    return map(int, s.split())

n_cases = input()

for case in xrange(1, n_cases + 1):
    r, t = to_ints(raw_input())

    # Mathematica:
    # Simplify[Solve[Sum[(r + 2 x + 1)^2 - (r + 2 x)^2, {x, 0, n - 1}] == t, {n}]]
    # n = 1/4 (1-2r+Sqrt[1-4r+4r^2+8t])

    n = int((-1 - 2*r + (1 - 4*r + 4*r*r + 8*t)**.5) / 4)

    while n * (-1 + 2*n + 2*r) < t:
        n += 1

    while n * (-1 + 2*n + 2*r) > t:
        n -= 1

    print "Case #%d: %s" % (case, n)
