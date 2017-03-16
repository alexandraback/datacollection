import sys, math
import random

P = [
    [2,2,2],
    [2,2,3],
    [2,2,4],
    [2,2,5],
    [2,3,3],
    [2,3,4],
    [2,3,5],
    [2,4,4],
    [2,4,5],
    [2,5,5],
    [3,3,3],
    [3,3,4],
    [3,3,5],
    [3,4,4],
    [3,4,5],
    [3,5,5],
    [4,4,4],
    [4,4,5],
    [4,5,5],
    [5,5,5]
]

D = [
[0,0,0],
[0,0,1],
[0,1,0],
[0,1,1],
[1,0,0],
[1,0,1],
[1,1,0],
[1,1,1]
]



def decompose(A):
    divisors = [2, 3, 5]
    d = [0, 0, 0, 0, 0, 0]
    i = 0
    while i < len(divisors) and A > 1:
        div = divisors[i]
        if A % div == 0:
            d[div] = d[div] + 1
            A = A / div
        else:
            i = i + 1

    return d

f = open(sys.argv[1])
T = int(f.readline())

F = [[0] * 126 for i in range(20)]

for p in range(len(P)):
    for d in range(len(D)):
        N = 1
        for x in range(3):
            if D[d][x] == 1:
                N = N * P[p][x]
        #print P[p], N
        F[p][N] = 1

print "Case #1:"
for i in range(T):
    (R, N, M, K) = f.readline().split()
    R = int(R)
    N = int(N)
    M = int(M)
    K = int(K)
    
    for r in range(R):
        gp = [0] * len(P)
        A = f.readline().split()

        #print A
        for a in A:
            for p in range(len(P)):
                if F[p][int(a)] == 1:
                    gp[p] = gp[p] + 1

        m = max(gp)
        for g in range(len(P)):
            if gp[g] == m:
                print str(P[g][0]) + str(P[g][1]) + str(P[g][2])
                break
        #print t
        
