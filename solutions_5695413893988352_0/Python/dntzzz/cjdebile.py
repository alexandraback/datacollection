from sys import stdin

T = int(stdin.readline())

for t in range(T):
    [c, j] = stdin.readline().strip().split(' ')


    mc = 999
    mj = 000
    md = 999
    
    if len(c) == 3:
        x = [int(c[0])] if c[0] != '?' else range(10)
        y = [int(c[1])] if c[1] != '?' else range(10)
        z = [int(c[2])] if c[2] != '?' else range(10)

        d = [int(j[0])] if j[0] != '?' else range(10)
        e = [int(j[1])] if j[1] != '?' else range(10)
        f = [int(j[2])] if j[2] != '?' else range(10)

        for xx in x:
            for yy in y:
                for zz in z:
                    for dd in d:
                        for ee in e:
                            for ff in f:
                                numc = 100*xx + 10*yy + zz
                                numj = 100*dd + 10*ee + ff
                                numd = abs(numc - numj)
                                if numd < md:
                                    md = numd
                                    mc = numc
                                    mj = numj
                                elif numd == md:
                                    if numc < mc:
                                        mc = numc
                                        mj = numj
                                    elif numc == mc and numj < mj:
                                        mc = numc
                                        mj = numj

    if len(c) == 2:
        x = [int(c[0])] if c[0] != '?' else range(10)
        y = [int(c[1])] if c[1] != '?' else range(10)

        d = [int(j[0])] if j[0] != '?' else range(10)
        e = [int(j[1])] if j[1] != '?' else range(10)

        for xx in x:
            for yy in y:
                for dd in d:
                    for ee in e:
                        numc = 10*xx + yy
                        numj = 10*dd + ee
                        numd = abs(numc - numj)
                        if numd < md:
                            md = numd
                            mc = numc
                            mj = numj
                        elif numd == md:
                            if numc < mc:
                                mc = numc
                                mj = numj
                            elif numc == mc and numj < mj:
                                mc = numc
                                mj = numj

    if len(c) == 1:
        x = [int(c[0])] if c[0] != '?' else range(10)
        d = [int(j[0])] if j[0] != '?' else range(10)

        for xx in x:
            for dd in d:
                numc = xx
                numj = dd
                numd = abs(numc - numj)
                if numd < md:
                    md = numd
                    mc = numc
                    mj = numj
                elif numd == md:
                    if numc < mc:
                        mc = numc
                        mj = numj
                    elif numc == mc and numj < mj:
                        mc = numc
                        mj = numj

    print 'Case #{}: {} {}'.format(t+1, str(mc).zfill(len(c)),
                                      str(mj).zfill(len(c)))

