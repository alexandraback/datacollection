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
            trace(args, ": got result from memo")
        except KeyError:
            result = f(*args)
            trace(args, ": got result by calling")
            memos[args] = result
        return result
    return memoized_f

n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    atrace( 'Case #', case_num )

    n_levels = int(getline())
    trace('n_levels =', n_levels)
    levels = []
    for i in range(n_levels):
        (a,b) = map(int, getline().split())
        trace('  ', a, b)
        levels.append((a,b,0))

    levels.sort(key=lambda (a,b,k): b)

    trace('sorted levels:', levels)

    # greedy
    n_completions = 0
    n_stars = 0
    n_levels_completed_at_rating_2 = 0
    while True:
        n_stars_at_top = n_stars
        trace('')

        trace('go for rating 2, starting with', n_stars, 'stars:')
        # complete as many levels at rating 2 as you can.
        for i,(a,b,k) in enumerate(levels):
            trace(' ', a,b,k)
            if k < 2:
                # hasn't completed at rating 2
                if n_stars >= b:
                    # complete it at rating 2
                    trace('  complete level', i, 'at rating 2')
                    n_stars += (2-k)
                    n_completions += 1
                    trace('  now have', n_stars, 'stars after', n_completions, 'completions')
                    levels[i] = (a,b,2)
                    n_levels_completed_at_rating_2 += 1

        if n_levels_completed_at_rating_2 == n_levels:
            trace('done!')
            result = n_completions
            break

        trace('go for rating 1:')
        # You can't complete any more at rating 2.
        # So pick *one* to complete at rating 1.
        # Of those you can complete at rating 1,
        # pick the one with the highest prereq for rating 2,
        # i.e. the least chance that you might be able to get
        # it in one go.
        for i in range(n_levels-1, -1, -1):
            (a,b,k) = levels[i]
            trace(' ', a,b,k)
            if k == 0 and n_stars >= a:
                # complete it at rating 1
                trace('  complete level', i, 'at rating 1')
                n_stars += 1
                n_completions += 1
                trace('  now have', n_stars, 'stars after', n_completions, 'completions')
                levels[i] = (a,b,1)
                break

        if (n_stars == n_stars_at_top):
            # no improvement
            result = 'Too Bad'
            break

    print 'Case #%d: %s' % (case_num, result)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
