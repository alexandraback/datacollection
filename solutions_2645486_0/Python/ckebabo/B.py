import sys

def readInts():
    return map(int, sys.stdin.readline().strip().split())

ret = 0

def foo(E,R,N,v, n,e,g):
    global ret
    
    if n==N:
        ret = max(ret, g)
        return
    
    foo(E,R,N,v, n+1, min(E,e+R), g+R)
    
    for x in xrange(1, e+1):
        foo(E,R,N,v, n+1, min(E,e-x+R), g+v[n]*x)
    
def solve(E,R,N, v):
    global ret
    ret = 0
    foo(E,R,N,v, 0, E,0)
                
    return ret

T = readInts()[0]
for case in xrange(1,T+1):
    E,R,N = readInts()
    v = readInts()

    print 'Case #%d: %d' % (case, solve(E,R,N, v))
