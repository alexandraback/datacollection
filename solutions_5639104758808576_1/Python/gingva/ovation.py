__author__ = 'dtrUdev'
import sys


def main(fn1, fn2):
    with open(fn1) as f:
        with open(fn2, 'w') as g:

            ncases = int(f.next().strip())
            for n in range(ncases):
                L = f.next().strip('\r\n').split()
                Smax = int(L[0])
                counts = [int(x) for x in L[1]]
                r = solve(counts)
                print >> g, 'Case #%d: %d'%(n+1, r)


def solve(counts):
    clapping = 0
    fans = 0
    for i,c in enumerate(counts):
        addedFans = max(0, i - clapping)
        clapping += c + addedFans
        fans += addedFans
    return fans

if __name__ == '__main__':
    main('A-test.in', 'A-test.out')
    main('A-small-attempt0.in', 'A-small-attempt0.out')
    main('A-large.in', 'A-large.out')
