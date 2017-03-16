import sys

def readInts():
    return map(int, sys.stdin.readline().strip().split())

def isPossible(land, N,M):
    for i in xrange(N):
        for j in xrange(M):
            n = land[i][j]

            row,col = True,True
            for k in xrange(N):
                if land[k][j] > n:
                    row = False
                    break

            for k in xrange(M):
                if land[i][k] > n:
                    col = False
                    break

            if row==False and col==False:
                return 'NO'
            
    return 'YES'

T = readInts()[0]
for case in xrange(1, T+1):
    N,M = readInts()

    land = [readInts() for _ in xrange(N)]

    print "Case #%d: %s" % (case, isPossible(land, N,M))
