
code = "A-large"

infile = code + ".in"
outfile = code + ".out"

E = 1e-9

def lowscore(s, v):
    return sum(v - si for si in s if si < v)

def findscore(s, si, v):
    low, high = 0.0, 1.0
    while high - low > E:
        mid = (low + high) / 2.0
        if lowscore(s, si + v * mid) < v * (1 - mid):
            low = mid
        else:
            high = mid
    return high

def solve(n, s):
    ss = sum(s)
    r = []
    for i, si in enumerate(s):
        sc = findscore(s[:i] + s[i+1:], si, ss)
        r.append(sc * 100.0)
    return r
                

lines = iter([s.strip() for s in open(infile)])
c = int(next(lines))
f = open(outfile, "w")
for i in range(1, c+1):
    z = map(int, next(lines).split())
    n = z[0]
    s = z[1:n+1]
    r = solve(n, s)
    print >> f, "Case #{}:".format(i), ' '.join('{:.6f}'.format(ri) for ri in r)
f.close()
