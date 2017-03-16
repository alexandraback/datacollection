#!/usr/bin/env python
T=int(raw_input().strip())


for i in range(1, T+1):
    N, M = raw_input().strip().split()
    N, M = int(N), int(M)
    lawn=[]
    for j in range(N):
        line=[ int(x) for x in raw_input().strip().split() ]
        lawn.append(line)
    stop=False
    for j in range(N):
        for k in range(M):
            rowok, colok=True, True
            for l in range(M):
                if lawn[j][k] < lawn[j][l]:
                    rowok=False
                    #print 'row',j,k,l,lawn[j][k], '>', lawn[j][l]
                    break
            for l in range(N):
                if lawn[j][k] < lawn[l][k]:
                    colok=False
                    break
            if rowok or colok:
                continue
            #print j,k
            stop=True
            break
        if stop:
            break

    if stop:
        print 'Case #%d: NO' % i
    else:
        print 'Case #%d: YES' % i

