#!/usr/bin/python
import sys, collections, math

data = file(sys.argv[1]).read().splitlines()

T = int(data.pop(0))

                 
def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b) 

def brute(P, Q):
    if P == 0:
        return int(math.log(Q,2))
    d = gcd(P,Q)
    P = P/d
    Q = Q/d

    for i in xrange(0, 41):
        curtwo = 2 ** i
        if Q == curtwo:
#            print 'curtwo', curtwo, P, Q
            return brute(P-1, Q)

    return 0


    minago = 41
    ago = 1
    curtwo = 1
    print P, Q

    while P:
        if ago == 41:
            return 0
        if curtwo == Q:
            P = P - 1
            minago = min(ago,minago)
        ago = ago + 1
        curtwo = curtwo * 2

    assert(P == 0)
    return minago

for numcase in xrange(1,T+1):
    print 'Case #%d:' % numcase,
    (P, Q) = [int(x) for x in data.pop(0).split('/')]
#    print P, Q

    v = brute(P, Q)
    if v == 0:
        print 'impossible'
    else:
        print v



    

    

