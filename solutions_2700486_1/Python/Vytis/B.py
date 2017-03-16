
code = "B-large"

infile = code + ".in"
outfile = code + ".out"

def fact(n):
    f = 1
    for i in xrange(n, 0, -1):
        f *= i
    return f

def C(n, k):
    return fact(n) / fact(k) / fact(n - k)

def solve(line):
    n, x, y = map(int, line.split())
    full = 0
    while n >= (1 + full * 4):
        n -= 1 + full * 4
        full += 1
    dist = (abs(x) + y) / 2
    if dist < full:
        return 1.0
    if dist > full:
        return 0.0
    m = full * 2
    if y >= m:
        return 0.0
    mi = max(0, n - m)
    ma = min(n, m)
    if y < mi:
        return 1.0
    if y >= ma:
        return 0.0
    def P(a, b):
        if a == m and b == m:
            return 2 ** (a + b)
        if a != m and b != m:
            return C(a + b, a)
        z = min(a, b)
        return sum(P(i, m - 1) * (2 ** (z - i)) for i in xrange(z + 1))
    p = 0
    h = ma
    while h > y:
        p += P(h, n - h)
        h -= 1
    qq = 1000000000
    return float(qq * p / (2 ** n)) / qq

lines = [s.strip() for s in open(infile)]
c = int(lines[0])
f = open(outfile, "w")
for i in range(1, c+1):
    r = solve(lines[i])
    msg = "Case #{}: {:.7f}".format(i, r)
    print msg
    print >> f, msg
f.close()
