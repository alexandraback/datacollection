#! /usr/bin/env python
import sys, re
import operator as op
import math

""" START TEMPLATE JCHAOISAAC """

# some reading functions
lolfile = open(sys.argv[1]) # open file
getline = lambda: lolfile.readline().strip()
gettoken = lambda: re.split("\s+", getline())
getint = lambda: int(getline())
getints = lambda: map(int, gettoken())

""" END TEMPLATE JCHAOISAAC """

# global data

cmap = {
    '.': 0,
    'X': 1,
    'O': 2,
    'T': 3,
    }

llist = [
    [0, 1, 2, 3],
    [4, 5, 6, 7],
    [8, 9, 10, 11],
    [12, 13, 14, 15],

    [0, 5, 10, 15],
    [12, 9, 6, 3],

    [0, 4, 8, 12],
    [1, 5, 9, 13],
    [2, 6, 10, 14],
    [3, 7, 11, 15],
]

# global data

def get_whiner(board):
    for l in llist:
        for c in [1, 2]:
            match = True
            for p in l:
                if not (board[p] & c):
                    match = False
                    break;
            if match:
                return c
    return 0


[T] = getints()
for cases in xrange(1, T + 1): # loop over cases
    ans = 0
    # main

    board = sum([[cmap[c] for c in getline()] for x in range(4)], [])
    getline()

    full = True;
    for x in board:
        if x == 0:
            full = False;
            break;

    whiner = get_whiner(board)

    ans = 'Game has not completed'
    if whiner == 2:
        ans = 'O won'
    elif whiner == 1:
        ans = 'X won'
    elif full:
        ans = 'Draw'

    # main
    print "Case #%d: %s" % (cases, ans) # answer output
