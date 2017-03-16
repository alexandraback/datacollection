"""
This script may use libraries publicly available at: https://github.com/grokit/dcore.

Does this solution solve:
   Small: ?.
   Big:   ?.
"""

import dcore.gcj_boot as boot

import math

def readProblem(fh):
    n = [int(x) for x in fh.readline().strip().split()]
    return n[0]

def optimizeDigit(sNum, iDigit, N):
    sNum = list(sNum)

    n = int(sNum[iDigit])
    best = -1
    for i in range(n, 10):
        pre = sNum[iDigit]
        sNum[iDigit] = str(i)

        sNum.reverse()
        nTry = int( "".join(sNum) )
        if nTry <= N:
            best = i
        sNum.reverse()

        sNum[iDigit] = pre

    return best

def fNext(i, N):
    cost = 1
    iS = str(i)
    S = []
    for digitOptimize in range(len(iS)-1, -1, -1):
        if digitOptimize > math.ceil(len(iS)/2) - 1:
            dopt = optimizeDigit(iS, digitOptimize, N)
            #print(i, digitOptimize, dopt)
            if dopt == -1:
                S.append( iS[digitOptimize] )
            else:
                orig = int(iS[digitOptimize])
                jump = (dopt - orig) * (10**(len(iS)-digitOptimize)-1)
                S.append( str(dopt) )
        else:
            S.append( iS[digitOptimize] )

    i2 = int( "".join(S) ) 

    if i2 > i+1 and i2 <= N:
        S.reverse()
        iJump = int("".join(S))
        cost = iJump - i + 1
        return (i2, cost)
    return (i+1, cost)

def solveH(N):

    t = 0
    i = 0
    while i < N:
        i, cost = fNext(i, N)
        #print(i, cost)
        t += cost

    return t

def jump(i):
    iS = list(str(i))
    iS.reverse()
    return int("".join(iS))

def solve(N):

    t = 0
    i = 0
    P = {}
    while i < N:
        iJump = jump(i)

        if iJump > i+1:
            P[iJump] = t+1

        i += 1
        t += 1

        if i in P:
            if P[i] < t:
                t = P[i]

    return t

boot.solve(solve, readProblem, '.*small')
