__author__ = 'gingva'

import sys,operator,time

def parseScalar(f,c=int):
    return c(f.next().strip('\r\n'))
def parseTuple(f,c=int):
    return tuple(c(s) for s in  f.next().strip('\r\n').split())


def main(fn1, fn2):
    with open(fn1) as f:
        with open(fn2, 'w') as g:
            t = time.time()
            ncases = int(f.next().strip())
            for n in range(ncases):
                R,C,W = parseTuple(f)
                m = solve(R,C,W)
                print>>g, 'Case #%d: %d'  % (n+1, m )
                print 'Case #%d: %d'  % (n+1, m )


def solve(R,C,W):
    assert R==1
    L = C
    cost = L / W - 1
    rest = L - cost * W
    if rest == W:
        return cost + W
    else:
        return cost + W + 1

    return a,b



if __name__ == '__main__':
    #main('A-test.in', 'A-test.out')
    main('A-small-attempt0.in', 'A-small-attempt0.out')
    #main('A-large.in', 'A-large.out')


