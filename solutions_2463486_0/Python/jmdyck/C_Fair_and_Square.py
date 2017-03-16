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

max_fas = 1000
# max_fas = 1e14
max_root = int(math.floor(math.sqrt(max_fas)))

def int_is_a_palindrome(n):
    digits = list(str(n))
    return (digits == list(reversed(digits)))

fair_and_square_numbers = []
for root in range(1, max_root+1):
    if int_is_a_palindrome(root):
        square = root * root
        if int_is_a_palindrome(square):
            # It's "fair and square"
            trace(root, '->', square)
            fair_and_square_numbers.append(square)

def count_fair_and_squares_in_range(a, b):
    # Return the number of fair and square numbers
    # greater than or equal to a and less than or equal to b.
    #
    # If there were a lot of F&S numbers,
    # one would do a binary search (since we have a sorted list),
    # for each endpoint, and subtract indices.
    # 
    # But there's so few that a linear search is fine.
    # (Only 39 up to 10^14.)
    # 
    # In fact, there's so few that we can test each individually
    # for whether it's in-range.
    # (Which is easier and less error-prone to code.)
    count = 0
    for fas_num in fair_and_square_numbers:
        if a <= fas_num <= b:
            count += 1
    return count

def read_and_do_case():
    (A,B) = map(int, getline().split())
    trace(A,B)
    return count_fair_and_squares_in_range(A,B)

n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    atrace( 'Case #', case_num )

    result = read_and_do_case()

    print 'Case #%d: %s' % (case_num, result)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
