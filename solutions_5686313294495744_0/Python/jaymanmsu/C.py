T = int(raw_input().strip())

for t in range(T):
    d = {}
    yd = {}
    xd = {}
    N = int(raw_input().strip())
    repcount = 0
    
    for n in range(N):
        X,Y = raw_input().strip().split(' ')
        if X in d:
            if Y in d[X]:
                d[X][Y] += 1
            else:
                d[X][Y] = 1
        else:
            d[X] = {}
            d[X][Y] = 1
        if X in xd:
            xd[X] += 1
        else:
            xd[X] = 1
        if Y in yd:
            yd[Y] += 1
        else:
            yd[Y] = 1
    #print d
    #print xd
    #print yd
    xl = len(xd)
    yl = len(yd)
    ans = str(N-max(xl, yl))
    # for y in yd:
        # ydd[y] = 0
    # for x in xd:
        # if xd[x] == 1:
            # continue
        # maxr = xd[x] - 1
        # for y in d[x]:
            # yv = d[x][y]
            # yc = min(yv, yd[y]-1, maxr)
            # repcount += yc
            # yd[y] -= yc
            # maxr -= yc
            # if maxr == 0:
                # break
        # print yd
    # ans = str(repcount)

    
    print "Case #%d: %s" % (t+1, ans)