#!/usr/bin/env python

# Given board position, determine winner of Tic-Tac-Toe-Tomek game.

import sys

from itertools import izip_longest

def grouper(n, iterable, fillvalue=None):
    "Collect data into fixed-length chunks or blocks"
    # grouper(3, 'ABCDEFG', 'x') --> ABC DEF Gxx
    args = [iter(iterable)] * n
    return izip_longest(fillvalue=fillvalue, *args)


def read(filename, num_lines):
    """Yield a "test" chunk of lines from filename."""
    first_line = None
    with open(filename, 'r') as f:
        if not first_line:
            first_line = f.readline()
        for chunk in grouper(num_lines, f, ''):
            yield chunk

def munge(test_chunks):
    """
    Yield a munged test from raw test_chunks.

    Test data structure:
        * List of 4 lines.
        * Each line is a 4-char string.

    """
    for chunk in test_chunks:
        test = chunk[0:4]
        yield [t.rstrip('\n') for t in test]

def lines(test):
    """
    Yield list of 10 possible winning lines for a test.

    * 4 horizontal lines
    * 4 vertical lines
    * 2 diagonal lines

    """
    # Horizontal
    for i in range(len(test)):
        yield test[i]

    # Vertical
    for j in range(len(test)):
        line = ""
        for k in range(len(test)):
            line = line + test[k][j]
        yield line 

    # Diagonal: top left to bottom right
    line = ""
    for i in range(len(test)):
        line = line + test[i][i]
    yield line

    # Diagonal: top right to bottom left
    line = ""
    for y, x in zip(range(4), range(3, -1, -1)):
        line = line + test[y][x]
    yield line

def game_state(test):
    """
    Return state of game.

    Return values:
        'X', if X won.
        'O', if O won.
        'draw', if no more moves are possible.
        'incomplete', if moves remain.

    """
    for line in lines(test):
        result = check_winner(line)
        if result in ['X', 'O']:
            return result

    # No winner, so determine if game is draw or incomplete.
    if any(['.' in x for x in test]):
        return 'incomplete'
    else:
        return 'draw'

def check_winner(line):
    """Return 'X' or 'O' if one player has won on line. Else, return None."""
    if all([x in ['X', 'T'] for x in line]):
        return 'X'
    elif all([x in ['O', 'T'] for x in line]):
        return 'O'
    else:
        return None

def format(index, state):
    """Format output properly."""
    output = "Case #%s: " % index
    if state in ['X', 'O']:
        output = output + "%s won" % state
    elif state == 'draw':
        output = output + "Draw"
    else:
        output = output + "Game has not completed"
    return output


def main(argv=None):
    if argv == None:
        argv = sys.argv

    if len(argv) != 2:
        sys.stderr.write("Usage: %s <input_file>" % argv[0])
        return 2

    infile = argv[1]
    raw = read(infile, 5)
    munged = munge(raw)

    for index, test in enumerate(munged):
        state = game_state(test)
        print format(index + 1, state)

if __name__ == '__main__':
    sys.exit(main())
