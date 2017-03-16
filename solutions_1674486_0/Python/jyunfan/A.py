from sys import stdin

def calc(N, L):
    for i in range(1, N+1):
        if P[i] == 0:
            1#print "test %d" % i
        else:
            continue
        Q = [i]
        A = [0] * (N+1)
        while len(Q)>0:
            node = Q.pop(0)
            for par in L[node]:
                if A[par] == 1:
                    return "Yes"
                A[par] = 1
                Q.append(par)
    return "No" 

T = int(stdin.readline())
for t in range(1, T+1):
    N = int(stdin.readline())
    L = []
    P = []
    for i in range(0,N+1):
        L.append([])
        P.append(0)
    for mi in range(1, N+1):
        M = stdin.readline().split()
        if len(M) == 1:
            continue
        for k in range(1, len(M)):
            L[mi].append(int(M[k]))
            P[int(M[k])] = mi
    print "Case #%d: %s" % (t, calc(N, L))
