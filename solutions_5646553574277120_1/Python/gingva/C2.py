def parseScalar(f,c=int):
    return c(f.next().strip('\r\n'))
def parseTuple(f,c=int):
    return tuple(c(s) for s in  f.next().strip('\r\n').split())


def main(fn1, fn2):
    with open(fn1) as f:
        with open(fn2, 'w') as g:
            ncases = parseScalar(f)
            for n in range(ncases):
                C,D,V = parseTuple(f)
                denom = parseTuple(f)
                assert len(denom) == D
                d = solve(C,denom,V)
                print>>g, 'Case #%d: %d'  % (n+1,d)
                print 'Case #%d: %d'  % (n+1,  d)


import numpy as np
import sys

def addOneDenom(maxCovered,d,C,V):
    assert(d<=maxCovered+1)
    return maxCovered+C*d

def solve(C,denom,V):
    maxCovered = 0
    added = 0
    for d in sorted(denom):
        while d > maxCovered+1:
            maxCovered = addOneDenom(maxCovered,maxCovered+1,C,V)
            added += 1
        maxCovered = addOneDenom(maxCovered,d,C,V)
    while maxCovered < V:
       maxCovered = addOneDenom(maxCovered,maxCovered+1,C,V)
       added += 1
    return added




    pass
if __name__ == '__main__':
    #main('C-test.in', 'C2-test.out')
    #main('C-small-attempt0.in', 'C2-small-attempt0.out')
    main('C-large.in', 'C-large.out')
    sys.exit(0)


