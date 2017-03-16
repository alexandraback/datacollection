imp = 'Impossible'

for test in range(input()):
    R,C,M = map(int, raw_input().split())
    r = R*C-M

    print 'Case #%s:' % (test+1)

    if r==1:
        print 'c'+'*'*(C-1)
        for _ in range(R-1):
            print '*'*C

    elif R==1:
        print 'c'+'.'*(r-1)+'*'*M

    elif C==1:
        print 'c'
        for _ in range(r-1): print '.'
        for _ in range(M): print '*'

    elif R==2:
        if r==2 or r%2!=0:
            print imp
        else:
            print 'c'+'.'*(r/2-1)+'*'*(C-r/2)
            print '.'*(r/2)+'*'*(C-r/2)

    elif C==2:
        if r==2 or r%2!=0:
            print imp
        else:
            print 'c.'
            for _ in range(r/2-1): print '..'
            for _ in range(R-r/2): print '**'

    elif r<=9:
        if r in (2, 3, 5, 7):
            print imp
        else:
            T = [
                None,
                ['c**', '***', '***'],
                None,
                None,
                ['c.*', '..*', '***'],
                None,
                ['c..', '...', '***'],
                None,
                ['c..', '...', '..*'],
                ['c..', '...', '...'],
            ]
            for y in range(R):
                print ''.join(T[r][y][x] if x<3 and y<3 else '*' for x in range(C))
    else:
        T = [['*']*C for y in range(R)]
        if r<=C*2:
            if r%2!=0:
                T[2][0] = T[2][1] = T[2][2] = '.'
                r -= 3
            for x in range(r/2):
                T[0][x] = T[1][x] = '.'
        else:
            for i in range(r):
                T[i/C][i%C] = '.'
            if r%C==1:
                if i/C==2:
                    T[2][1] = T[2][2] = '.'
                    T[0][-1] = T[1][-1] = '*'
                else:
                    T[i/C][1] = '.'
                    T[i/C-1][-1] = '*'
        T[0][0] = 'c'
        for t in T:
            print ''.join(t)
