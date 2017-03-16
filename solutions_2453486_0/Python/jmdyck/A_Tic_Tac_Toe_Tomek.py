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

# ---------------------

def get_status(board):
    # Horizontal win?
    for row in board:
        check_win(list(row))

    # Vertical win?
    for j in range(4):
        check_win([ row[j] for row in board ])

    # Diagonal win?
    check_win( [ board[i][i] for i in range(4) ])
    check_win( [ board[i][3-i] for i in range(4) ])

    # Draw?
    for row in board:
        if '.' in row:
            break
    else:
        raise Answer("Draw")

    raise Answer("Game has not completed")

def check_win(line):
    n = {'X': 0, 'O': 0, '.': 0, 'T': 0}
    for c in line:
        n[c] += 1
    if n['X'] == 4 or (n['X'] == 3 and n['T'] == 1):
        raise Answer("X won")
    if n['O'] == 4 or (n['O'] == 3 and n['T'] == 1):
        raise Answer("O won")

class Answer:
    def __init__(self, s):
        self.s = s

n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    atrace( 'Case #', case_num )

    board = [
        getline(),
        getline(),
        getline(),
        getline(),
    ]
    assert getline() == ''

    try:
        get_status(board)
    except Answer, a:
        status = a.s

    print 'Case #%d: %s' % (case_num, status)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
