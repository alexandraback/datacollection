#!/usr/bin/python

import sys, math

INPUT = sys.stdin
INPUT = open(sys.argv[1],'r')

def getline():
    return INPUT.readline()[:-1]

class Bunch:
    def __init__( self, **kwds ):
        self.__dict__ = kwds


pause_after_trace = False
def trace(*strs):
    atrace(*strs)

def atrace(*strs):
    f = sys.stderr
    print >> f, '..',
    for str in strs:
        print >> f, str,
    print >> f
    if pause_after_trace:
        response = raw_input('? ')
        if response == 'q':
            sys.exit(1)

def memoize(f):
    memos = {}
    def memoized_f( *args ):
        try:
            result = memos[args]
            trace(args, ": got result from memo")
        except KeyError:
            result = f(*args)
            trace(args, ": got result by calling")
            memos[args] = result
        return result
    return memoized_f

# ------------------------------------------------------------------------------

n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    atrace( 'Case #', case_num )

    (r, t) = map(int, getline().split())

    # The first ring has area:
    #    pi * (r+1)^2 - pi * r^2
    # requiring:
    #    (r+1)^2 - r^2            =   2r + 1
    # millilitres of paint.
    #
    # The second ring:
    #    pi * (r+3)^2 - pi * (r+2)^2
    # requires:
    #    (r+3)^2 - (r+2)^2        =   2r + 5
    #
    # The nth ring requires:
    #    (r+2n-1)^2 - (r+2n-2)^2  =   2r + 4n - 3
    #
    # So all n rings require
    #
    # sigma [i=1 to n] (2r + 4i - 3)
    # 
    # = sigma [] (2r) + sigma [] (4i) - sigma [] (3)
    # =       n * 2r  + 4 sigma [1 to n] (i) -      n * 3
    # =       2rn  + 4 * n * (n+1) / 2   - 3n
    # =  2 ( n^2 + n ) + 2rn - 3n
    # =  2 n^2 + (2r-1) n
    #
    # so what is the largest integral n such that [that] is less than t?
    # 
    # find the n such that [that] is equal to t, then take the floor.
    # i.e., find (positive) root of
    #   2 n^2 + (2r-1) n - t
    # 
    a = 2
    b = 2 * r - 1
    c = -t

    disc = math.sqrt(b*b - 4 * a * c)
    root1 = (-b + disc) / (2 * a)

    maxn = int(math.floor(root1))

    # but I'm afraid of round-off errors.

    def paint_used(n_rings):
        return a * n_rings * n_rings + b * n_rings

    p = paint_used(maxn)
    if p == t:
        pass
    elif p > t:
        while True:
            maxn -= 1
            if paint_used(maxn) <= t: break
    elif p < t:
        while True:
            if paint_used(maxn+1) > t: break
            maxn += 1
    else:
        assert 0

    print 'Case #%d: %s' % (case_num, maxn)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
