import os

__author__ = 'dkopiychenko'

def more(l, t):
    c = 0
    for x in l:
        if x > t:
            c += 1
    return c



def solve(g):
    t = []
    for x in g:
        t.append((360. - x[0])/x[1])
    m = len(g)

    for x in g:
        t0 = (360. - x[0])/x[1]
        n1 = more(t, t0)
        c = n1
        for y in g:
            if x == y: continue
            w = y[1] - x[1]
            if w > 0:
                tt1 = 360./w
                tt2 = 1.*(x[0] - y[0])/w
                if (tt1 + tt2) <= t0:
                    c += int((t0-tt2)/tt1)
        if c < m:
            m = c
    return m
#
# def solve3(g):
#     t = []
#     for x in g:
#         t.append((360. - x[0])/x[1])
#     m = len(g)
#
#     for x in g:
#         t0 = (360. - x[0])/x[1]
#         n1 = more(t, t0)
#         c = n1
#         for y in g:
#             if x == y: continue
#             w = y[1] - x[1]
#             if w > 0:
#                 tt1 = 360./w
#                 tt2 = 1.*(x[0] - y[0])/w
#                 if (tt1 + tt2) < t0:
#                     c += int((t0-tt2)/tt1)
#         if c < m:
#             m = c
#     return m


# def solve2(g):
#     if g[0][0] < g[1][0]:
#         h1 = g[0]
#         h2 = g[1]
#     else:
#         h1 = g[1]
#         h2 = g[0]
#     t1 = (360 - h1[0])/h1[1]
#     t2 = (360 - h2[0])/h2[1]
#     t0 = max(t1, t2)
#     w = h2[1] - h1[1]
#     if w > 0:
#         a = 360. + h1[0] - h2[0]
#         tt = a/w
#     else:
#         a = 360. + h2[0] - h1[0]
#         tt = a/abs(w)
#     if tt > t0:
#         return 0
#     else: return 1



with open(os.path.expanduser("~/Downloads/C-small-2-attempt2.in")) as f:
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
