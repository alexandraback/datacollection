from fractions import gcd
import math

inf = open("A-small-attempt1.in")
outf = open("A-small-attempt1.out", "w")

EPS = 1e-10

numTests = int(inf.readline().rstrip())

def can(score, points, gain):
    for p in points:
        if p < score:
            gain -= score - p
    return gain > EPS


def getMinScoreSingle(p, points):
    l = 0
    r = 1.0
    s = sum(points) + p
    for i in range(100):
        k = (l + r) / 2.0
        if can(p + k * s, points, (1 - k) * s):
            l = k
        else:
            r = k
    return l * 100

def getMinScore(points):
    res = []
    for i in range(len(points)):
        res.append("%.10f"  % getMinScoreSingle(points[i], points[:i] + points[i + 1:]))
    return " ".join(res)

for test in range(numTests):
    data = list(map(int, inf.readline().split()))
    _, points = data[0], data[1:]
    print("Case #%d: %s" % (test + 1, getMinScore(points)), file=outf)

