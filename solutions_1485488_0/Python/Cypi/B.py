#! /usr/bin/python
# -*-coding:Utf-8 -*

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())


T = readint()
for t in range(T):
    print 'Case #'+str(t+1)+':',
    
    H,N,M = readarray(int)

    C = []
    for i in range(N):
        C.append(readarray(int))
    F = []
    for i in range(N):
        F.append(readarray(int))

    T = []
    for i in range(N):
        T.append([])
        for j in range(M):
            T[i].append(2**31)
    
    T[0][0] = 0

    q = [(0, 0)]

    while q:
        i,j = q.pop()
        v = []
        if i > 0:
            v.append((i-1, j))
        if j > 0:
            v.append((i, j-1))
        if i < N-1:
            v.append((i+1, j))
        if j < M-1:
            v.append((i, j+1))
        for (c,d) in v:
            if C[c][d] < F[c][d]+50 or F[c][d] > C[i][j] - 50:
                continue
            h = H - T[i][j]
            wait = max(0, 50 - C[c][d] + h)
            p = 100 if (h - wait) - F[i][j] < 20 else 10
            if wait == 0 and T[i][j] == 0:
                wait = -p
            if T[c][d] > wait+T[i][j]+p:
                q.append((c,d))
                T[c][d] = wait+T[i][j]+p
    print T[N-1][M-1]/10.

