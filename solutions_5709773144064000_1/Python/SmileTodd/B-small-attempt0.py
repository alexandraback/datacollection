import sys

def solve(C,F,X):
    n = 0.0
    t = 0.0
    if (X>C):
        while ( X/(2+(n+1)*F)<(X-C)/(2+n*F) ):
            t+= C/(2+n*F)
            n+=1
    t+=X/(2+n*F)
    return "%.7f" % t

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
    attr = [float(i) for i in sys.stdin.readline().strip().split()]
    print 'Case #' + repr(casenum) + ": "+ solve(attr[0],attr[1],attr[2])

    
