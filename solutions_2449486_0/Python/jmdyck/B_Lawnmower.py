#!/usr/bin/python

import sys

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

def case_result():
    (N,M) = map(int, getline().split())
    desired_height_ = []
    for i in range(N):
        row = map(int, getline().split())
        assert len(row) == M
        desired_height_.append(row)

    for i in range(N):
        trace(
            ' '.join(
                ('%3d' % desired_height_[i][j]) for j in range(M)
            )
        )

    max_height_in_row_ = [
        max([
            desired_height_[i][j]
            for j in range(M)
        ])
        for i in range(N)
    ]

    max_height_in_col_ = [
        max([
            desired_height_[i][j]
            for i in range(N)
        ])
        for j in range(M)
    ]

    for i in range(N):
        for j in range(M):
            h = desired_height_[i][j]
            if h == min(max_height_in_row_[i], max_height_in_col_[j]):
                pass
            else:
                return "NO"

    return "YES"

n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    atrace( 'Case #', case_num )

    print 'Case #%d: %s' % (case_num, case_result())
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
