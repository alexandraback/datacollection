
code = "B-small-attempt1"

infile = code + ".in"
outfile = code + ".out"

def solve(n, s):
    s.sort(key=lambda (a, b): (b, a))
    got1 = [False] * n
    got2 = 0
    stars = 0
    plays = 0
    while got2 < n:
        if s[got2][1] <= stars:
            stars += 1 if got1[got2] else 2
            plays += 1
            got2 += 1
            continue
        for i in reversed(range(got2, n)):
            if s[i][0] <= stars and not got1[i]:
                stars += 1
                plays += 1
                got1[i] = True
                break
        else:
            return "Too Bad"
    return plays

lines = iter([s.strip() for s in open(infile)])
c = int(next(lines))
f = open(outfile, "w")
for i in range(1, c+1):
    n = int(next(lines))
    s = [map(int, next(lines).split()) for j in xrange(n)]
    r = solve(n, s)
    print >> f, "Case #%d:" % i, r
f.close()
