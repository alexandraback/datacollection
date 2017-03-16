import math
from fractions import gcd

def exp2(Q):
    N = 0
    isexp2 = True
    q = 1
    while q<Q:
        q = q*2
        if q<=Q:
            N = N+1
        else:
            isexp2 = False

    return [N,isexp2]
        
        
##inputFile = open('A-sample.in','r')
##outputFile = open('A-sample.ou','w')
inputFile = open('A-small-attempt0.in','r')
outputFile = open('A-small-attempt0.ou','w')
##inputFile = open('A-large.in','r')
##outputFile = open('A-large.ou','w')
numTest = int(inputFile.readline())
for testid in range(1,numTest+1):
    P,Q = [int(s) for s in inputFile.readline().split('/')]
    print(P,Q)
    D = gcd(P,Q)
    P = P//D
    Q = Q//D
    print(P,Q,D)
    [N,isN] = exp2(Q)
    [M,isM] = exp2(P)
    print('M,N=',M,isM,N,isN)

    if not isN:         
        print('Case #',testid,': impossible', sep='',file=outputFile)
    else:
        print('Case #',testid,': ',N-M, sep='',file=outputFile)


outputFile.close()
    
        
