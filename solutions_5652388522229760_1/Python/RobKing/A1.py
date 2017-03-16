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
    if N == 0:
        print "Case #%d: INSOMNIA" %(T+1)
    else:
        A = [0,0,0,0,0,0,0,0,0,0]
        index = 1
        while 0 in A:
            D = getdigits(N*index)
            # print D
            for d in D:
                A[d] = 1
            if 0 in A:
                index += 1
            else:
                print "Case #%d: %d" %(T+1,N*index)

cases = int(raw_input())
for T in xrange(cases):
    N = int(raw_input())
    solve(T, N)
