T = int(raw_input())

for t in xrange(T):
    R, C, M = map(int, raw_input().split())
    
    F = R * C - M
    
    ans = [['*'] * C for _ in xrange(R)]
    
    ans[R - 1][C - 1] = 'c'
    
    ok = True
    
    if F == 1:
        ok = True
    elif R == 1:    
        for c in xrange(M, C - 1):
            ans[R - 1][c] = '.'
        ok = True
    elif C == 1:
        for r in xrange(M, R - 1):
            ans[r][C - 1] = '.'
        ok = True
    else:
        if R == 2 or C == 2:
            if F & 1 or F == 2:
                ok = False
            else:
                ok = True
                if R == 2:
                    for c in xrange(M // 2, C):
                        ans[0][c] = '.'
                        ans[1][c] = '.'
                else:
                    for r in xrange(M // 2, R):
                        ans[r][0] = '.'
                        ans[r][1] = '.'
                ans[R - 1][C - 1] = 'c'
        elif F in [3, 5, 7]:
            ok = False
        else:
            ans[R - 1][C - 1] = '*'
            ans[0][0] = 'c'
            ans[0][1] = '.'
            ans[1][0] = '.'
            ans[1][1] = '.'
            
            xx = 0
            yy = 0
            for x in xrange(2, C + 1):
                for y in xrange(2, R + 1):
                    if 2 * x + 2 * y - 4 <= F and x * y >= F:
                        xx = x
                        yy = y
                        break
            if xx == 0 and yy == 0:
                ok = False
            else:
                ok = True
                for c in xrange(xx):
                    ans[0][c] = '.'
                    ans[1][c] = '.'
                for r in xrange(2, yy):
                    ans[r][0] = '.'
                    ans[r][1] = '.'
                ans[0][0] = 'c'
                F -= 2 * xx + 2 * yy - 4
                if xx != 2:
                    for r in xrange(2, (F // (xx - 2)) + 2 ):
                        for c in xrange(2, xx):
                            ans[r][c] = '.'
                    r = F // (xx - 2)
                    F -= (xx - 2) * r
                    r += 2
                    for c in xrange(2, 2 + F):
                        ans[r][c] = '.'


    if ok:
        print "Case #{}:\n{}".format(t + 1, '\n'.join((''.join(a) for a in ans)))
    else:
        print "Case #{}:\n{}".format(t + 1, "Impossible")
        