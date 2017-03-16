__author__ = 'dtrUdev'
import sys, math


def main(fn1, fn2):
    with open(fn1) as f:
        with open(fn2, 'w') as g:
            ncases = int(f.next().strip())
            for n in range(ncases):
                D = int(f.next().strip('\r\n'))
                plates = [int(x) for x in f.next().strip('\r\n').split()]
                r = solve(plates)
                print >> g, 'Case #%d: %d'%(n+1, r)



def imax(l):
    if not l:
        return -1,0
    im,m = 0,l[0]
    for i,n in enumerate(l):
        if n > m:
            im,m = i,n
    return im,m


# the minutes to go is either the max number of pancakes or 1 + the max that we achieve by splitting
# the max we achieve is ceil(max(cakes)/2.0)
# a double recursion gives the same answer...
def solve(plates):
    im, m = imax(plates)
    if m <= 2:
        return m
    else:
        # 2. special
        s1 = int(math.floor(float(m)/2.0))
        s2 = int(math.ceil(float(m)/2.0))
        plates3 = plates[:im] + plates[im+1:] + [s1, s2]
        solSpecial = 1 + solve(plates3)

        # 1. let them eat
        solWait = m


        return min(solWait, solSpecial)



if __name__ == '__main__':
    main('B-test.in', 'B-test.out')
    main('B-small-attempt1.in', 'B-small-attempt1a.out')
    #main('B-large.in', 'B-large.out')

