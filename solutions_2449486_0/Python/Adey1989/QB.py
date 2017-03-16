import sys

f = open(sys.argv[1])
T = int(f.readline())

def delelems(arr,dels):
    enum = list(enumerate(arr))
    return [item for i,item in enum if i not in dels]

def ispossible(lawn,N,M):
    exit = 0
    while exit != 1:
        minelem = min(lawn)
        #print lawn
        innerexit = 0
        for ii in range(N):
            rows = range(ii*M,ii*M+M)
            #print rows, 'row', ii, [lawn[kk] for kk in rows]
            if max([lawn[kk] for kk in rows]) == minelem:
                lawn = delelems(lawn, rows)
                N = N - 1
                innerexit = 1
                break
        if innerexit == 0:
            for jj in range(M):
                cols = range(jj,M*N+jj,M)
                #print cols, 'col', jj, [lawn[kk] for kk in cols]
                if max([lawn[kk] for kk in cols]) == minelem:
                    lawn = delelems(lawn,cols)
                    M = M - 1
                    innerexit = 1
                    break
        if lawn==[]:
            return 'YES'
        else:
            if innerexit == 0:
                return 'NO'

for test in range(T):
    N, M = map(int,f.readline().split(' '))
    lawn = []
    for ii in range(N):
        lawn = lawn + list(map(int,f.readline().split(' ')))

    print "Case #%d: " % (test+1) + ispossible(lawn,N,M)



    #print x