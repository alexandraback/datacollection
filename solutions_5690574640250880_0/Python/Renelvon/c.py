def solve(R, C, M, transpose=False):
    board = None
    Spaces = R * C - M

    if Spaces == 1:
        board = [['*' for i in range(C)] for j in range(R)]
        board[0][0] = 'c'

    elif R == 1:
        board = [['c'] + ['.' for i in range(Spaces - 1)] + ['*' for i in range(M)]]

    elif R == 2:
        if Spaces >= 4 and Spaces % 2 == 0:
            SS = Spaces // 2
            board2 = ['.' for i in range(SS)] + ['*' for j in range(C - SS)]
            board1 = board2.copy()
            board1[0] = 'c'
            board = [board1, board2]

    elif R == 3:
        if Spaces >= 6 and Spaces % 3 == 0:
            SS = Spaces // 3
            board3 = ['.' for i in range(SS)] + ['*' for j in range(C - SS)]
            board1 = board3.copy()
            board1[0] = 'c'
            board = [board1, board3, board3]

        elif Spaces >= 8 and (Spaces - 2) % 3 == 0:
            SS = (Spaces + 1) // 3
            board3 = ['.' for i in range(SS)] + ['*' for j in range(C - SS)]
            board2 = board3.copy()
            board1 = board3.copy()
            board3[SS - 1] = '*'
            board1[0] = 'c'
            board = [board1, board2, board3]

        elif (Spaces == 4 or Spaces >= 10) and (Spaces - 1) % 3 == 0:
            SS = (Spaces + 2) // 3
            board3 = ['.' for i in range(SS)] + ['*' for j in range(C - SS)]
            board2 = board3.copy()
            board1 = board3.copy()
            board3[SS - 1] = '*'
            board3[SS - 2] = '*'
            board1[0] = 'c'
            board = [board1, board2, board3]

    elif R >= 4:
        full_lines = min(M // C, R - 4)

        all_mines = ['*' for i in range(C)]
        all_empty = ['.' for i in range(C)]

        restM = M - full_lines * C

        if restM < C - 1:
            board = solve(3, C, 0, False)
            for i in range(R - full_lines - 4):
                board.append(all_empty)

            midline = ['.' for i in range(C - restM)] + ['*' for j in range(restM)]
            board.append(midline)

            for i in range(full_lines):
                board.append(all_mines)

        elif restM == C - 1:
            board = solve(2, C, 0, False)
            for i in range(R - full_lines - 4):
                board.append(all_empty)

            midline0 = all_empty.copy()
            midline0[C - 1] = '*'
            board.append(midline0)

            midline1 = all_mines.copy()
            midline1[0] = '.'
            midline1[1] = '.'
            board.append(midline1)

            for i in range(full_lines):
                board.append(all_mines)

        else:
            board = solve(3, C, restM - C, False)
            if board:
                board.append(all_mines)
                for i in range(full_lines):
                    board.append(all_mines)

    if board and transpose:
        return list(zip(*board))
    return board 

def print_board(board):
    for row in board:
        print(*row, sep='')

def check(board, R, C, M):
    numrow = len(board) == R
    numcol = len(board[0]) == C
    numines = sum([board[i].count('*') for i in range(R)]) == M

    return numrow and numcol and numines

def main():
    T = int(input())
    for i in range(1, T + 1):
        R, C, M = [int(s) for s in input().strip().split()]
        print('Case #', i, ':', sep='')
        if R <= C:
            result = solve(R, C, M, False)
        else:
            result = solve(C, R, M, True)

        if result:
            #print(check(result, R, C, M))
            print_board(result)
        else:
            print('Impossible')

if __name__ == '__main__':
    main()
