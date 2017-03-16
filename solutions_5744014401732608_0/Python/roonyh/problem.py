fo = open("sm.in", "r")

T = int(fo.readline())


for zzz in range(T):
    b, m = [int(l) for l in fo.readline().split()]
    pos = True



    l = []

    for i in xrange(b):
        l.append([])
        for j in xrange(b):
            l[i].append(0)

    def prnl():
        for ll in l:
            print " ".join([str(lll) for lll in ll])

    if m >= 1:
        l[0][b-1] = 1

    d = 1

    curr = 1
    while d < b-1:
        if(d==m):
            break;
        l[0][curr] = 1
        l[curr][b-1] = 1

        d+=1
        curr+=1

    st = 1
    lef = m - 2
    cur = 1



    while(m > d):
        if(lef<=0):
            pos = False
            break

        done = False
        for x in xrange(cur+1, b-1):

            d += st
            l[x][cur] = 1
            if(d==m):
                done = True
                break
            if(d>m):
                if(d-1 == m):
                    l[0][b-1] = 0
                    done = True


                done = True
                pos = False
                break
        if done:
            break
        cur += 1
        lef -= 1
        st += 1

    if m < b-1:
        pass

    print 'Case #%d: %s' % (zzz+1, 'POSSIBLE' if pos else 'IMPOSSIBLE')
    if pos:
        prnl()

