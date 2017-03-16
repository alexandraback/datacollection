#!/usr/bin/python
#
# Tom Moertel <tom@moertel.com>
# 2013-04-13


"""Solution to "Tic-Tac-Toe-Tomek" Code Jam problem
https://code.google.com/codejam/contest/2270488/dashboard

"""

import fileinput

def main():
    for i, p in enumerate(read_problems(fileinput.input()), 1):
        s = solve(p)
        print 'Case #%r: %s' % (i, s)

def solve(problem):
    board = problem
    winner = find_winners(board, 4)
    if not winner:
        if any('.' in row for row in board):
            return 'Game has not completed'
        return 'Draw'
    return '%s won' % (winner, )

def find_winners(board, K):
    N = len(board)
    for row in xrange(N):
        for col in xrange(N):
            if row != 0 and col != 0:
                continue  # start from upper and left edges only
            for color in 'X', 'O':
                for rdir in -1, 0, 1:
                    for cdir in -1, 0, 1:
                        if rdir == cdir == 0:
                            continue
                        if is_winner(board, row, col, color, rdir, cdir, K):
                            return color
    return None

def is_winner(board, row, col, color_code, rdir, cdir, k):
    N = len(board)
    while k and 0 <= row < N and 0 <= col < N:
        if board[row][col] not in (color_code, 'T'):
            break
        k -= 1
        row += rdir
        col += cdir
    return k == 0

def read_problems(lines):
    T = int(lines.next())
    for _ in xrange(T):
        yield read_problem(lines)

def read_problem(lines):
    board = [lines.next().strip() for _ in xrange(4)]
    try:
        lines.next() # skip trailing blank
    except StopIteration:
        pass
    return board

def read_ints(lines):
    return [int(s) for s in lines.next().strip()]

if __name__ == '__main__':
    main()
