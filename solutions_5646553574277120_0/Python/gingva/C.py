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

def addOneDenom(covered,d,V,C):
        oldcovered = set(covered)
        for i in xrange(1,C+1):
            covered.add(i*d)
        for c in oldcovered:
            for i in xrange(1,C+1):
                if c+i*d <= V:
                    covered.add(c+i*d)


def solve(C,denom,V):
    covered = set()
    for d in denom:
        addOneDenom(covered,d,V,C)
    missing = set(xrange(1,V+1)).difference(covered)
    if len(missing) == 0:
        return 0
    added = 0
    while missing:
        d = min(missing)
        added += 1
        addOneDenom(covered,d,V,C)
        missing = set(xrange(1,V+1)).difference(covered)
    return added




    pass
if __name__ == '__main__':
    #main('C-test.in', 'C-test.out')
    main('C-small-attempt0.in', 'C-small-attempt0.out')
    #main('C-large.in', 'B-large.out')
    sys.exit(0)


