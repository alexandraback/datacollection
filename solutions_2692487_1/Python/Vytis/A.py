
code = "A-large"

infile = code + ".in"
outfile = code + ".out"

def solve(a, o):
    o.sort()
    n = len(o)
    i = 0
    while i < n and o[i] < a:
        a += o[i]
        i += 1
    m = n - i
    if a <= 1:
        return m
    add = 0
    while i < n:
        a += a - 1
        add += 1
        while i < n and o[i] < a:
            a += o[i]
            i += 1
        m = min(m, n - i + add)
    return m

lines = [s.strip() for s in open(infile)]
c = int(lines[0])
f = open(outfile, "w")
lineno = 1
for i in range(1, c+1):
    a, n = map(int, lines[lineno].split())
    o = map(int, lines[lineno+1].split())
    r = solve(a, o)
    lineno += 2
    print >> f, "Case #%d:" % i, r
f.close()
