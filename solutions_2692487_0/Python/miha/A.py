import sys
import bisect

#f = open('A-test.in','r')
f = sys.stdin
T = int(f.readline())

def check(A, M):
    n = 0
    while True:
        while(len(M)>0 and M[0]<A):
            A += M[0]
            del M[0]
        if len(M)==0:
            return n
        M.insert(0, A-1)
        n += 1
    return -1

for t in xrange(T):
    A, N = map(lambda x: int(x), f.readline().split())
    M = map(lambda x: int(x), f.readline().split())
    #print A, N, M
    M.sort()

    result = len(M)
    if A>1:
        for i in xrange(N):
            n = check(A, M[0:i+1])
            #print '---',i, n
            if n==-1: continue
            if(n + N-i-1 < result ):
                result = n + N-i-1
            #print 'i',n,result, M[0:i+1]

    print 'Case #%d: %d'%(t+1,result)

