from sys import stdin

T = int(stdin.readline())
for case in xrange(1, T+1):
    n = int(stdin.readline())
    hikers = []
    i = 0
    out = None
    for ni in xrange(n):
        d, h, m = map(int, stdin.readline().split(' '))
        for nh in xrange(h):
            hikers.append([d, float(m + nh) / 360, i])
            i += 1
    if hikers[0][0] < hikers[1][0]:
        h1 = hikers[0]
        h2 = hikers[1]
    else:
        h1 = hikers[1]
        h2 = hikers[0]
    t1 = (360 - h1[0]) * h1[1]
    t2 = (360 - h2[0]) * h2[1]
    if t1 <= t2:
        if t1 + 360 * h1[1] <= t2:
            out = 1
        else:
            out = 0
    else:
        if t1 <= t2 + 360*h2[1]:
            out = 0
        else:
            out = 1
    print "Case #%d: %d" % (case, out)
