#!/usr/bin/env python

from sys import stdin

T = int(stdin.readline())

for tt in range(T):
    wds = stdin.readline().split()
    H = float(wds[0])
    N = int(wds[1])
    M = int(wds[2])

    cei = []
    flo = []
    for n in range(N):
        wds = stdin.readline().split()
        cei.append([float(m) for m in wds])
        pass
    for n in range(N):
        wds = stdin.readline().split()
        flo.append([float(m) for m in wds])
        pass

    mas_time = [ [ -1. for m in range(M) ] for n in range(N) ]
    mas_time[0][0] = 0.
    nodes = [(0,0)]
    time = 0

    while True:
        kouho = []
        for i, j in nodes[:]:
            cut_check = True
            for ii, jj in [(i, j+1), (i, j-1), (i+1, j), (i-1, j)]:
                if ii < 0 or ii >= N: continue
                if jj < 0 or jj >= M: continue
                if mas_time[ii][jj] >= 0.: continue

                if flo[i][j]   > cei[ii][jj] - 50.: continue
                if flo[ii][jj] > cei[i][j]   - 50.: continue
                if flo[ii][jj] > cei[ii][jj] - 50.: continue

                h = cei[ii][jj] - 50.
                if h > H and mas_time[i][j] == 0.:
                    t = 0.
                else:
                    t1 = max((H - h)/10., mas_time[i][j])
                    h = H - t1*10.
                    #print flo[i][j], h, "debug"
                    if h >= flo[i][j] + 20.:
                        t2 = 1.
                    else:
                        t2 = 10.
                        pass
                    t = t1 + t2
                    pass
                cut_check = False
                if not (t, ii, jj) in kouho: kouho.append((t, ii, jj))
                continue
            if cut_check: nodes.remove((i,j))
            continue

        kouho.sort()
        #print kouho
        #print mas_time
        keika = kouho[0][0]
        for t, i, j in kouho:
            if t > keika: break
            mas_time[i][j] = t
            nodes.append((i,j))
            continue

        #print mas_time
        if mas_time[N-1][M-1] >= 0.: break
        continue

    print "Case #%d: %7f" % (tt+1, mas_time[N-1][M-1])
