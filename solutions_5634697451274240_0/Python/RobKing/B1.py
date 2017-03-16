from sys import *


def getdigits(M):
    result = []
    while M >= 10:
        Temp = M
        M = M / 10
        result.append(Temp - 10 * M)
    result.append(M)
    return result

def solve(T, N):
    A = []
    for i in range(len(N)):
        if N[i] == '-':
            A.append(False)
        else:
            A.append(True)

    move = 0
    while False in A:
        for i in range(len(A))[::-1]:
            if A[i] == False:
                for j in range(i+1):
                    A[j] = not A[j]
                break
        move += 1
    
    print "Case #%d: %d" %(T+1, move)


cases = int(raw_input())
for T in xrange(cases):
    N = raw_input()
    solve(T, N)
