import sys

f=sys.stdin

T = int(f.readline())
for t in xrange(T):
    N, M = map(lambda x: int(x), f.readline().split())
    a = [ map(lambda x: int(x), f.readline().split()) for i in xrange(N)]
    S = [ [0 for i in xrange(M)] for i in xrange(N) ]

    E = []
    for i in xrange(N):
        for j in xrange(M):
            E.append((a[i][j], i ,j))
    E.sort()
    #print E

    for h, ei,ej in E:
        if S[ei][ej] == 1:
            continue
        rv = 1
        for i in xrange(N):
            if a[i][ej] > h:
                rv = 0
        rh = 1
        for j in xrange(M):
            if a[ei][j] > h:
                rh = 0
        #print rv,rh
        if rh==1 or rv==1:
            S[ei][ej] = 1
        else:
            break
            

    s = 0
    for i in xrange(N):
        for j in xrange(M):
            s += S[i][j]
    print 'Case #%d: %s'%(t+1, 'YES' if s==N*M else 'NO')
