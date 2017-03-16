
code = "A-small-attempt0"

infile = code + ".in"
outfile = code + ".out"

def solve(a, b, p):
    best = b + 2
    pb = 1
    for i, pp in enumerate(p):
        z = (a - i) + (b - i) + 1
        best = min(best, z + (b + 1) * (1 - pb))
        pb *= pp
    z = (b - a) + 1
    best = min(best, z + (b + 1) * (1 - pb))
    return best

lines = iter([s.strip() for s in open(infile)])
c = int(next(lines))
f = open(outfile, "w")
for i in range(1, c+1):
    a, b = map(int, next(lines).split())
    p = map(float, next(lines).split())
    r = solve(a, b, p)
    print >> f, "Case #%d: %.8f" % (i, r)
f.close()
