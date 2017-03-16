import sys

def readInts():
    return map(int, sys.stdin.readline().strip().split())

def need(r,n):
    return n*(2*r-3) + 2*n*(1+n)

def maxNumber(r,t):
    l = 1
    h = t

    while l<h:
        if h-l == 1:
            break
        
        m = (l+h)/2

        if need(r,m) > t:
            h = m
        else:
            l = m

    if need(r,h) <= t:
        return h

    if need(r,m) <= t:
        return m
    
    return l

T = readInts()[0]
for case in xrange(1, T+1):
    r,t = readInts()

    print 'Case #%d: %d' % (case, maxNumber(r,t))
