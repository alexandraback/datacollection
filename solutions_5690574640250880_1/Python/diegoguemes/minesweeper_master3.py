def create_board(R, C):
    board = []
    for i in range(R):
        row = []
        for j in range(C):
            row.append('.')
        board.append(row)
    return board

def minesweeper(R, C, M):
    board = create_board(R, C)
    if R * C - 1 == M:
        for i in range(R):
            for j in range(C):
                board[i][j] = '*'
    else:
        columns = False
        for i in range(R):
            for j in range(C):
                if M == 0 or columns:
                    break
                if C - j - M >= 2 and i + 1 != R:
                    board[i][j] = '*'
                    M -= 1
                    continue
                if i == R - 2 or C - j > M:
                    columns = True
                    for k in range(C):
                        for l in range(i, R):
                            if M == 0:
                                break
                            board[l][k] = '*'
                            M -= 1
                else:
                    board[i][j] = '*'
                    M -= 1
    board[-1][-1] = 'c'
    #print(board_str(board))
    has_empty_cell = False
    for i in range(R):
        for j in range(C):
            if board[i][j] == '.':
                has_empty_cell = True
    wrong_cell = False
    for i in range(R):
        if C - 1 > 0 and board[i][C - 1] == '.' and board[i][C - 2] == '*':
            wrong_cell = True
    for i in range(C):
        if R - 1 > 0 and board[R - 1][i] == '.' and board[R - 2][i] == '*':
            wrong_cell = True


    if has_empty_cell and wrong_cell:
        return 'Impossible'
    return board_str(board)

def board_str(board):
    if len(board) == 1:
        return '\n'.join([''.join(row) for row in board])
    return '\n'.join([''.join(row) for row in board])

import unittest

class MinesweeperTest(unittest.TestCase):
    def test_1(self):
        self.assertEqual(
            "c",
            minesweeper(1, 1, 0)
        )

    def test_2(self):
        self.assertEqual(
            "**\n" +
            "*c",
            minesweeper(2, 2, 3)
        )

    def test_3(self):
        self.assertEqual(
            "*.c",
            minesweeper(1, 3, 1)
        )

    def test_4(self):
        self.assertEqual(
            "*\n" +
            ".\n" +
            "c",
            minesweeper(3, 1, 1)
        )

    def test_5(self):
        self.assertEqual(
            "***\n" +
            "...\n" +
            "..c",
            minesweeper(3, 3, 3)
        )
        self.assertEqual(
            "****\n" +
            "....\n" +
            "...c",
            minesweeper(3, 4, 4)
        )
        self.assertEqual(
            "****\n" +
            "****\n" +
            "....\n" +
            "...c",
            minesweeper(4, 4, 8)
        )

    def test_6(self):
        self.assertEqual(
            "****\n" +
            "**..\n" +
            "....\n" +
            "...c",
            minesweeper(4, 4, 6)
        )

    def test_7(self):
        self.assertEqual(
            "***\n" +
            "*..\n" +
            "*.c",
            minesweeper(3, 3, 5)
        )

    def test_8(self):
        self.assertEqual(
            "****\n" +
            "**..\n" +
            "**.c",
            minesweeper(3, 4, 8)
        )

    def test_9(self):
        self.assertEqual(
            "**..\n" +
            "**.c",
            minesweeper(2, 4, 4)
        )

    def test_10(self):
        self.assertEqual(
            "**...\n" +
            "*....\n" +
            "*...c",
            minesweeper(3, 5, 4)
        )

    def test_11(self):
        self.assertEqual(
            "*****\n" +
            "**...\n" +
            "*....\n" +
            "*...c",
            minesweeper(4, 5, 9)
        )

    def test_12(self):
        self.assertEqual(
            "Impossible",
            minesweeper(2, 2, 1)
        )

    def test_13(self):
        self.assertEqual(
            "Impossible",
            minesweeper(5, 5, 23)
        )

    def test_14(self):
        self.assertEqual(
            "Impossible",
            minesweeper(4, 7, 3)
        )

import sys
T = int(sys.stdin.readline())
for t in range(1, T + 1):
    R, C, M = [int(x) for x in sys.stdin.readline().split()]
    print('Case #{0}:'.format(t))
    print(minesweeper(R, C, M))

