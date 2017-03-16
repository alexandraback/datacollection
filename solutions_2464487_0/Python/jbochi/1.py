def area(r):
    return 2 * r + 1

def solve(r, t):
    i = 0
    while t > 0:
        t -= area(r)
        r += 2
        if t >= 0:
            i += 1
    return i

with open("1.in") as f:
    c = [map(int, l.strip().split()) for l in f.readlines()]
    for t in range(c[0][0]):
        print "Case #%d: %s" % (t + 1, solve(*c[t + 1]))
