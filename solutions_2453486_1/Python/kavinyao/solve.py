# -*- coding:utf-8 -*-
import sys
import itertools

def streak4(line, sym):
    """Test if all characters in line is sym or 'T'"""
    return all(c == 'T' or c == sym for c in line)

def who_win(line):
    if '.' in line:
        return False
    elif 'X' in line and 'O' in line:
        return False
    elif streak4(line, 'X'):
        return 'X won'
    else:
        return 'O won'

def solve(lines):
    """Juedge winner."""
    # horizontal
    for line in lines:
        res = who_win(line)
        if res: return res

    # for rest cases, convert to matrix first
    matrix = ''.join(lines)

    # diagonal
    res = who_win(matrix[::5])
    if res: return res
    res = who_win(matrix[3::3][:4])
    if res: return res

    # vertical
    for i in range(4):
        res = who_win(matrix[i::4])
        if res: return res

    if any('.' in l for l in lines):
        return 'Game has not completed'
    else:
        return 'Draw'

if __name__ == '__main__':
    output = open(sys.argv[2], 'w')

    with open(sys.argv[1]) as test:
        rounds = int(test.next())

        for i in xrange(rounds):
            lines = [test.next(), test.next(), test.next(), test.next()]
            matrix = [line.rstrip() for line in lines]
            res = solve(matrix)
            output.write("Case #%d: %s\n" % (i+1, res))
            # consume test case separator
            test.next()

    output.close()
