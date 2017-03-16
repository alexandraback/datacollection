"""area of 1cm ring

a = pi (rout^2 - rin^2)
  = pi ((r+1)^2 - r^2)
  = pi (r^2 + 2 * r + 1 - r^2)
  = pi (2 * r + 1)


pi (2 * r + 1 + 2 * (r + 2) + 1 + 2 * (r + 4) + 1 + ...)
pi (2 * r + 1 + 2 * r + 4 + 1 + 2 * r + 8 + 1 + ...)

for n rings:
pi (2 * r * n + n + (0 + 4 + 8 + ...))

pi (2 * r * n + n + 4 * (1 + 2 + ... + n - 1))

pi (2 * r * n + n + 4 * (n * (n - 1) / 2))

pi (2 * r * n + n + 2 * n * (n - 1))

pi (2 * r * n + n + 2n^2 - 2n)

pi (2rn + n + 2n^2 - 2n)

pi (n(2r + 1 - 2) + 2n^2)

pi (2n^2 + n * (2r - 1))

1 stripe at r=1: 3 (good)
1 stripe at r=3: 16 - 9 = 7 = 2 + 5
2 stripes at r=1 = 3 + 7 = 10 = 8 + 2 = 10
"""

def total(r, n):
    return 2 * n ** 2 + n * (2 * r - 1)

def solve(r, t):

    lo, hi = 1, 2

    if total(r, lo) == t:
        return lo
    assert total(r, lo) < t

    #double until over
    while total(r, hi) < t:
        lo, hi = hi, hi * 2

    if total(r, lo) == t:
        return lo
    if total(r, hi) == t:
        return hi

    #binary search
    while (hi - lo) > 1:

        mid = lo + (hi - lo) / 2

        x = total(r, mid)

        if x == t:
            return mid

        if x < t:
            lo = mid
        else:
            assert x > t, "%s %s" % (x, t)
            hi = mid

    if lo == hi:
        return lo

    assert hi - lo == 1
    assert total(r, hi) >= t
    assert total(r, lo) <= t
    if total(r, hi) == t:
        return hi

    return lo

assert solve(1, 9) == 1, solve(1, 9)
assert solve(1, 10) == 2, solve(1, 10)
assert solve(3, 40) == 3, solve(3, 40)
assert solve(1, 1000000000000000000) == 707106780
assert solve(10000000000000000, 1000000000000000000) == 49


def main():

    import sys

    data = open(sys.argv[1] + '.in').readlines()
    nt = int(data[0])

    outfile = open(sys.argv[1] + '.out', 'w')

    for i in range(nt):
        r, t = map(int, data[i + 1].split())
        result = solve(r, t)
        assert total(r, result) <= t, "%s %s" % (total(r, result), t)
        assert total(r, result+1) > t
        print "Case #%i: %i" % (i + 1, result)

        outfile.write("Case #%i: %i\n" % (i + 1, result))

    outfile.close()


if __name__ == "__main__":
    main()
