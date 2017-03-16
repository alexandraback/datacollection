#!/usr/bin/python

import sys, operator

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

def product(x):
    return reduce(operator.mul, x)

n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    atrace( 'Case #', case_num )

    (n_chars_typed, n_chars_in_pw) = map(int,getline().split())
    n_chars_left = n_chars_in_pw-n_chars_typed
    trace('%s chars typed, %s chars in pw, so %s to go' %
        (n_chars_typed, n_chars_in_pw, n_chars_left))
    p_corr_ = map(float,getline().split())
    trace('p_corr_:', p_corr_)
    assert len(p_corr_) == n_chars_typed

    things = []

    trace()
    trace('if hit enter now:')
    assert n_chars_left > 0 # A < B
    # so hitting enter now will never succeed
    # regardless of whether sofar is correct or incorrect,
    # enter + ps + enter
    e = 1 + n_chars_in_pw + 1
    trace('expectation:', e)
    things.append( (e, 'hit enter now') )

    cumulative_prob_ = [1.0]
    for i in range(1, n_chars_typed+1):
        cumulative_prob_.append( p_corr_[i-1] * cumulative_prob_[i-1] )

    
    pc = 1
    for b in range(n_chars_typed, -1, -1):
        trace()
        n_chars_remaining_in_field = n_chars_typed - b
        n_chars_typed_after_backspacing = n_chars_in_pw - n_chars_remaining_in_field
        trace('if backspace %s times, leaving %d in form, then proceed to type %d:' %
            (b, n_chars_remaining_in_field, n_chars_typed_after_backspacing)
        )

        kc = b + n_chars_typed_after_backspacing + 1
        ec = pc * kc
        trace('prob %s that chars-in-form are correct; %d strokes; %s' % (pc, kc, ec))

        pi = 1-pc
        ki = kc + n_chars_in_pw + 1
        ei = pi * ki
        trace('prob %s that chars-in-form are incorrect; %d strokes; %s' % (pi, ki, ei))

        e = ec+ei
        trace('expectation:', e)
        things.append((e, 'backspace %d' % b))

        if b != 0: pc *= p_corr_[n_chars_remaining_in_field]

    # --------------

    things.sort()
    best = things[0][0]

    print 'Case #%d: %s' % (case_num, best)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
