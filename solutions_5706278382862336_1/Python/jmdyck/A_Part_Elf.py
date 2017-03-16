#!/usr/bin/python

import sys, fractions

INPUT = sys.stdin
INPUT = open(sys.argv[1],'r')

def getline():
    return INPUT.readline()[:-1]

class Bunch:
    def __init__( self, **kwds ):
        self.__dict__ = kwds


pause_after_trace = False
def mtrace(*strs):
    return
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
            mtrace(args, ": got result from memo")
        except KeyError:
            result = f(*args)
            mtrace(args, ": got result by calling")
            memos[args] = result
        return result
    return memoized_f

# ------------------------------------------------------------------------------

powers_of_2 = [ pow(2,i) for i in range(40) ]

n_cases = int(getline())
mtrace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    mtrace()
    atrace( 'Case #', case_num )

    (P, Q) = map(int, getline().split('/'))
    mtrace(P,Q)
    # mtrace('{:b}'.format(Q))
    g = fractions.gcd(P,Q)
    mtrace('gcd:', g)
    P = P / g
    Q = Q / g
    mtrace('reduced:', P, Q)

    def solve(p, q):
        if p >= q:
            return 0
        else:
            return 1 + solve(p, q/2)

    if Q in powers_of_2:
        result = solve(P,Q)
    else:
        result = 'impossible'

    print 'Case #%d: %s' % (case_num, result)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
