#!/bin/python3

T = int(input())




for t in range(T):
    JP = [[0]*12 for i in range(12)]
    PS = [[0]*12 for i in range(12)]
    JS = [[0]*12 for i in range(12)]

    J, P, S, K = list(map(int, input().split()))

    result = []
    modified = True
    while modified:
        modified = False
        for j in range(J):
            for p in range(P):
                for s in range(S):
                    if JP[j][p] < K and JS[j][s] < K and PS[p][s] < K:
                        JP[j][p] += 1
                        JS[j][s] += 1
                        PS[p][s] += 1
                        result.append( (str(j+1), str(p+1), str(s+1)) )
                        modified = True

    if J == 1 and P == 1 and S == 1:
        result = [('1', '1', '1')]

    print("Case #" + str(t + 1) + ": " + str(len(result)))
    for r in result:
        print(" ".join(r))
