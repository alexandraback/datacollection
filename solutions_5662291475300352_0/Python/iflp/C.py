from fractions import *

def solve(v1, p1, v2, p2):
    if (p1 > p2):
        [p1, p2] = [p2, p1]
        [v1, v2] = [v2, v1]
    if (v1 == v2):
        return 0
    v1 = Fraction(360, v1)
    v2 = Fraction(360, v2)
    if (v1 < v2):
        dis = Fraction(360 - (p2 - p1), 1)
        if dis / (v2 - v1) * v1 + p1 > 360:
            return 0
        else:
            return 1
    else:
        time = Fraction(p2 - p1, v1 - v2)
        pos = time * v1 + p1
        if pos > 360:
            return 0
        else:
            pos1 = pos + Fraction(360, v1 - v2) * v2
            if (pos1 > 360):
                return 0
            else:
                return 1

n = int(input())
for i in range(1, n + 1):
    t = int(input())
    s = []
    for j in range(t):
        d, h, m = [int(i) for i in input().split(' ')]
        for k in range(h):
            s += [[d, m]]

    print("Case #", i, ": ", end='', sep='')
    if (len(s) == 1):
        print("0")
    else:
        print(solve(s[0][1], s[0][0], s[1][1], s[1][0]))

