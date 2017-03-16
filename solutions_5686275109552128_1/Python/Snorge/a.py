import sys
import math

z = []
with open(sys.argv[1]) as t:
    for l in t:
        z.append(l.split())


for i in range(1, len(z)-1, 2):
    n = z[i+1]

    o = []

    for j in n:
        o.append(int(j))

    p = sorted(o, reverse=True)

    b = p[0]
    c = 0

    for j in range(b):
        c += 1
        l = p[:]
        e = 0
        for d in l:
            if d > c:
                e += math.ceil((d - c) / c)

        if c + e < b:
            b = c + e

    print("Case #" + str((i+1)//2) + ": " + str(b))

