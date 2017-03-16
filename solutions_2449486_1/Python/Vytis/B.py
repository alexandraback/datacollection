
from string import ascii_lowercase

code = "B-large"

infile = code + ".in"
outfile = code + ".out"

def solve(n, m, lines):
    lawn = [map(int, line.split())
        for line in lines]
    row = [max(r) for r in lawn]
    col = [max(r[i] for r in lawn) for i in xrange(m)]
    good = all(lawn[i][j] == row[i] or lawn[i][j] == col[j]
        for i in xrange(n) for j in xrange(m))
    return 'YES' if good else 'NO'

lines = [s.strip() for s in open(infile)]
c = int(lines[0])
f = open(outfile, "w")
lineno = 1
for i in range(1, c+1):
    n, m = map(int, lines[lineno].split())
    r = solve(n, m, lines[lineno+1:lineno+1+n])
    lineno += 1 + n
    print >> f, "Case #%d:" % i, r
f.close()
