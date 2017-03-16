import sys
stdin = sys.stdin

T = int(stdin.readline())
for tcase in range(T):
    N = int(stdin.readline())
    naomi = map(float, stdin.readline().split())
    ken =   map(float, stdin.readline().split())

    naomi.sort()
    ken.sort()

    wn = naomi[:]
    wk = ken[:]
    wre = 0
    for w in wk:
        if wn[0] < w:
            wre += 1
            wn = wn[1:]
    wre = N - wre

    dwre = 0
    for w in naomi:
        if ken[0] < w:
            ken = ken[1:]
            dwre += 1
        elif ken[-1] > w:
            ken = ken[:-1]
        else:
            dwre += 1

    print "Case #%d: %d %d" % (tcase+1, dwre, wre)
