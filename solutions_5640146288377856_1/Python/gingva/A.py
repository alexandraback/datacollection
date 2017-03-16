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
    L = C
    cost1 = C / W * (R-1)
    L = C
    cost2 = C / W - 1
    rest = L - cost2 * W
    if rest == W:
        return cost1 + cost2 + W
    else:
        return cost1 + cost2 + W + 1




if __name__ == '__main__':
    #main('A-test.in', 'A2-test.out')
    #main('A-small-attempt0.in', 'A2-small-attempt0.out')
    main('A-large.in', 'A-large.out')


