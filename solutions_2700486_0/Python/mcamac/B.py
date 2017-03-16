from math import *

def chd(n, m):
    s = 0
    for j in range(m):
        s += log(n - j)
        s -= log(m - j)

    s -= n * log(2)
    return exp(s)


T = input()

for c in range(1, T + 1):
    [N, X, Y] = map(int, raw_input().split())

    if N == 1:
        print "Case #%d: %0.8f" % (c, 1 if [X,Y] == [0,0] else 0)
        continue


    base = 1
    while ((base + 2) * (base + 3)) / 2 <= N:
        base +=2
    baseN = (base * (base + 1))/2

    if abs(X) + abs(Y) <= (base / 2) * 2:
        print "Case #%d: %0.8f" % (c, 1)
        continue

    if abs(X) + abs(Y) >= (base / 2) * 2 + 4:
        print "Case #%d: %0.8f" % (c, 0)
        continue

    extra = N - baseN


    if X == 0:
        print "Case #%d: %0.8f" % (c, 1 if N== baseN else 0)
        continue



    need = Y + 1

    ans = sum(chd(extra, x) for x in range(need, extra+1))

    print "Case #%d: %0.8f" % (c, ans)

