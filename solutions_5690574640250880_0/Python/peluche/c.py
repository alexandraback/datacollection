#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Problem C. Minesweeper Master
Confused? Read the quick-start guide.
Small input
11 points
You may try multiple times, with penalties for wrong submissions.
Large input
24 points
You must solve the small input first.
You have 8 minutes to solve 1 input file. (Judged after contest.)
Problem

Minesweeper is a computer game that became popular in the 1980s, and is still included in some versions of the Microsoft Windows operating system. This problem has a similar idea, but it does not assume you have played Minesweeper.

In this problem, you are playing a game on a grid of identical cells. The content of each cell is initially hidden. There are M mines hidden in M different cells of the grid. No other cells contain mines. You may click on any cell to reveal it. If the revealed cell contains a mine, then the game is over, and you lose. Otherwise, the revealed cell will contain a digit between 0 and 8, inclusive, which corresponds to the number of neighboring cells that contain mines. Two cells are neighbors if they share a corner or an edge. Additionally, if the revealed cell contains a 0, then all of the neighbors of the revealed cell are automatically revealed as well, recursively. When all the cells that don't contain mines have been revealed, the game ends, and you win.

For example, an initial configuration of the board may look like this ('*' denotes a mine, and 'c' is the first clicked cell):

*..*...**.
....*.....
..c..*....
........*.
..........

There are no mines adjacent to the clicked cell, so when it is revealed, it becomes a 0, and its 8 adjacent cells are revealed as well. This process continues, resulting in the following board:

*..*...**.
1112*.....
00012*....
00001111*.
00000001..

At this point, there are still un-revealed cells that do not contain mines (denoted by '.' characters), so the player has to click again in order to continue the game.

You want to win the game as quickly as possible. There is nothing quicker than winning in one click. Given the size of the board (R x C) and the number of hidden mines M, is it possible (however unlikely) to win in one click? You may choose where you click. If it is possible, then print any valid mine configuration and the coordinates of your click, following the specifications in the Output section. Otherwise, print "Impossible".
Input

The first line of the input gives the number of test cases, T. T lines follow. Each line contains three space-separated integers: R, C, and M.
Output

For each test case, output a line containing "Case #x:", where x is the test case number (starting from 1). On the following R lines, output the board configuration with C characters per line, using '.' to represent an empty cell, '*' to represent a cell that contains a mine, and 'c' to represent the clicked cell.

If there is no possible configuration, then instead of the grid, output a line with "Impossible" instead. If there are multiple possible configurations, output any one of them.
Limits

0 ≤ M < R * C.
Small dataset

1 ≤ T ≤ 230.
1 ≤ R, C ≤ 5.
Large dataset

1 ≤ T ≤ 140.
1 ≤ R, C ≤ 50.
"""

def memo(f):
    def foo(R, C, empty, board):
        if board not in memorie:
            memorie[board] = f(R, C, empty, board)
        return memorie[board]
    return foo

def border(R, C, board):
    ret = []
    for i in range(R):
        for j in range(C):
            if board[i*C + j] == '*':
                if (i > 0 and board[(i-1)*C + j] != '*' and (j == 0 or board[(i)*C + j - 1] != '*')) or (j > 0 and board[i*C + j - 1] != '*' and (i == 0 or board[(i - 1)*C + j] != '*')):
                    ret.append((i, j))
    return ret

def place_clicks(R, C, board, i, j):
    if (i < R - 1 and board[(i+1)*C + j] == '*') or (j < C - 1 and board[i*C + j + 1] == '*') or (i < R -1 and j < C - 1 and board[(i+1)*C+j+1] == '*'):
        return False
    if i < R - 1:
        board[(i+1)*C + j] = 'c'
    if j < C - 1:
        board[i*C + j + 1] = 'c'
    if i < R - 1 and j < C - 1:
        board[(i + 1) * C + j + 1] = 'c'
    return True

def pp(R, C, board):
    for line in zip(*[iter(board)]*C):
        print ''.join(line)

def click_rec(R, C, board):
    flag = False
    for i in range(R):
        for j in range(C):
            if board[i*C + j] == 'c':
                board[i*C + j] = '-'
                flag = place_clicks(R, C, board, i, j) or flag
    if flag:
        return click_rec(R, C, board)
    else:
        return '.' not in board

def click(R, C, board):
    return click_rec(R, C, [c for c in board])

@memo
def gen_boards(R, C, empty, board):
    if empty == 0:
        if click(R, C, board):
            return board
        return ''
    for i, j in border(R, C, board):
        ind = i * C + j
        new_board = board[:ind]+'.'+board[ind+1:]
        ret = gen_boards(R, C, empty - 1, new_board)
        if ret != '':
            return ret
    return ''

def solve(R, C, M):
    """
    R = rows
    C = columns
    M = mines
    """
    imp = "Impossible"
    empty = R * C - M
    if empty < 1:
        return imp
    board = 'c' + ('*' * (R * C - 1))
    ret = gen_boards(R, C, empty - 1, board)
    return ret

def main():
    T = int(raw_input())
    for i in range(1, T + 1):
        global memorie
        memorie = {}
        R, C, M = map(int, raw_input().split())
        res = solve(R, C, M)
        print "Case #{}:".format(i)
        if res == '': print "Impossible"
        else: pp(R, C, res)

def test():
    board = "\
c....\
.....\
....."
    ret = border(3, 5, board)
    print ret
    # ---
    print click(3, 5, board)


if __name__ == '__main__':
    main()
    # test()
