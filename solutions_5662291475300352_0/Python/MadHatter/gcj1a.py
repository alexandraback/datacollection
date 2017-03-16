import os

__author__ = 'dkopiychenko'


def solve(g):
    if len(g) > 2: return ">2"
    if g[0][0] < g[1][0]:
        h1 = g[0]
        h2 = g[1]
    else:
        h1 = g[1]
        h2 = g[0]
    t1 = (360 - h1[0])/h1[1]
    t2 = (360 - h2[0])/h2[1]
    t0 = max(t1, t2)
    w = h2[1] - h1[1]
    if w > 0:
        a = 360. + h1[0] - h2[0]
        tt = a/w
    else:
        a = 360. + h2[0] - h1[0]
        tt = a/abs(w)
    if tt > t0:
        return 0
    else: return 1


with open(os.path.expanduser("~/Downloads/C-small-1-attempt0.in")) as f:
#with open(os.path.expanduser("~/gcj2015/A-test.in.txt")) as f:
    n = int(f.readline().strip('\n'))
    print n
    for i in range(n):
        m = int(f.readline().strip('\n'))
        g = []
        for j in range(m):

            r,c,m = [int(nn) for nn in f.readline().strip('\n').split(' ')]
            for x in range(c):
                g.append((r, 360./(m + x)))

        res = solve(g)
        print 'Case #' + str(i+1) + ': ' + str(res)
