import math

def area(r):
    return 2 * r + 1

def solve(r, t):
    a = 2
    b = area(r) - 2
    c = -t
    result = (-b + math.sqrt(math.pow(b, 2) - 4 * a * c)) / 2 / a
    return int(math.floor(result))

with open("1.in") as f:
    c = [map(int, l.strip().split()) for l in f.readlines()]
    for t in range(c[0][0]):
        print "Case #%d: %s" % (t + 1, solve(*c[t + 1]))
