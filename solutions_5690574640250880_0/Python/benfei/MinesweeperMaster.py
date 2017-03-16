__author__ = 'Ben'

from string import Template


def main():
    T = int(input())
    result = ""
    result_line = Template('Case #$x:\n$y\n')

    for instance in range(1, T + 1):
        (R, C, M) = map(int, input().split())

        if M == R*C - 1:
            result += result_line.substitute(x=instance, y=draw_board(R, C, M))
        elif R == 1 or C == 1:
            result += result_line.substitute(x=instance, y=draw_board(R, C, M))
        elif R >= 3 and C >= 3:
            if M in (R*C-7, R*C-5, R*C-3, R*C-2):
                result += result_line.substitute(x=instance, y='Impossible')
            else:
                result += result_line.substitute(x=instance, y=draw_board(R, C, M))
        else:
            if M % 2 == 1 or M == R*C - 2:
                result += result_line.substitute(x=instance, y='Impossible')
            else:
                result += result_line.substitute(x=instance, y=draw_board(R, C, M))

    print(result[:-1], end='')


def get_board(R, C, M):
    transpose = False
    board = []
    if R < C:
        (R, C) = (C, R)
        transpose = True

    if R == 3 and C == 3:
        if M == 0:
            board = [['.', '.', '.'], ['.', '.', '.'], ['.', '.', 'c']]
        elif M == 1:
            board = [['*', '.', '.'], ['.', '.', '.'], ['.', '.', 'c']]
        elif M == 3:
            board = [['*', '*', '*'], ['.', '.', '.'], ['.', '.', 'c']]
        elif M == 5:
            board = [['*', '*', '*'], ['*', '.', '.'], ['*', '.', 'c']]
        elif M == 8:
            board = [['*', '*', '*'], ['*', '*', '*'], ['*', '*', 'c']]
        return board

    elif C >= 3:
        if M <= C*(R-3):
            for row in range(M//C):
                board.append(['*']*C)
            if (M % C) == C - 1:
                board.append(['*']*(C-2) + ['.']*2)
                board.append(['*'] + ['.']*(C-1))
            else:
                board.append(['*']*(M%C) + ['.']*(C-M%C))
                board.append(['.']*C)
            for row in range(R-M//C-3):
                board.append(['.']*C)
            board.append(['.']*(C-1) + ['c'])

        else:
            for row in range(R-3):
                board.append(['*']*C)
            board += get_board(3, C, M-C*(R-3))

    elif C == 2:
        for row in range(M//2):
            board.append(['*']*2)
        for row in range(R-M//2-1):
            board.append(['.']*2)
        if M % 2 == 1:
            board.append(['*', 'c'])
        else:
            board.append(['.', 'c'])

    elif C == 1:
        for row in range(M):
            board.append(['*'])
        for row in range(R*C-M-1):
            board.append(['.'])
        board.append(['c'])

    if transpose:
        board = list(zip(*board))
    return board


def draw(board):
    for row in range(len(board)):
        board[row] = ''.join(board[row])
    return '\n'.join(board)


def draw_board(R, C, M):
    return draw(get_board(R, C, M))


if __name__ == "__main__":
    main()