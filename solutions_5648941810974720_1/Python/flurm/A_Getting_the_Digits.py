#!/usr/bin/python

import sys, collections, pprint

INPUT = sys.stdin
INPUT = open(sys.argv[1],'r')

def getline():
    return INPUT.readline()[:-1]

class Bunch:
    def __init__( self, **kwds ):
        self.__dict__ = kwds


pause_after_trace = False
def mtrace(*strs):
    # return
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

english_reps = [ "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" ]
letter_counts_for_digit_ = []
for digit, rep in enumerate(english_reps):
    letter_counts_ = collections.defaultdict(int)
    for letter in rep:
        letter_counts_[letter] += 1
    letter_counts_for_digit_.append(letter_counts_)
# pprint.pprint(letter_counts_for_digit_)

extraction_order = [
    ('Z',0),
    ('W',2),
    ('U',4),
    ('X',6),
    ('G',8),
    #
    ('H',3), # or 'R' or 'T'
    ('F',5),
    ('S',7),
    #
    ('O',1),
    ('I',9),
]

n_cases = int(getline())
mtrace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    mtrace()
    atrace( 'Case #', case_num )

    letter_count_ = collections.defaultdict(int)
    letters = getline()
    for letter in letters:
        letter_count_[letter] += 1

    digit_count_ = {}

    for (letter, digit) in extraction_order:
        k = letter_count_[letter]
        digit_count_[digit] = k

        for (d_letter, d_count) in letter_counts_for_digit_[digit].items():
            letter_count_[d_letter] -= d_count * k
            assert letter_count_[d_letter] >= 0
    
    assert max(letter_count_.values()) == 0

    phone_num = ''
    for (digit, count) in sorted(digit_count_.items()):
        phone_num += ( str(digit) * count )

    print 'Case #%d: %s' % (case_num, phone_num)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
