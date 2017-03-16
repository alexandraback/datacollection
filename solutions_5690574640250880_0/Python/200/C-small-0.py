directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

def recursively_verify(board, row, column):
    if 0 < row < len(board) - 1 and 0 < column < len(board[0]) - 1:
        if board[row][column] == ' ':
            return 0
        board[row][column] = ' '
        for row_offset, column_offset in directions:
            if board[row + row_offset][column + column_offset] == '*':
                return 1
        count = 1
        for row_offset, column_offset in directions:
            count += recursively_verify(board, row + row_offset, column + column_offset)
        return count
    return 0

def verify_solution(board):
    new_board = [['.' for column in range(len(board[0]) + 2)] for row in range(len(board) + 2)]
    count = 1
    for row in range(len(board)):
        for column in range(len(board[0])):
            flag = board[row][column]
            new_board[row + 1][column + 1] = flag
            if flag == 'c':
                start_row = row + 1
                start_column = column + 1
            elif flag == '.':
                count += 1
    return count == recursively_verify(new_board, start_row, start_column)


from sys import stdin, stdout
from collections import defaultdict

def rec_dd():
    return defaultdict(rec_dd)

def oneclickable(R, C, M):
    if M < 0:
        return ()
    swaped = R > C
    if swaped:
        R, C = C, R
    cache = oneclickable_records[R][C][M]
    if type(cache) == type(()):
        result = cache
    else:
        if M == 0:
            result = (R, C, M)
        elif M >= R:
            result = ()
            if C > 2:
                result = oneclickable(R, C - 1, M - R)
            if len(result) == 0 and R > 2:
                result = oneclickable(R - 1, C, M - C)
        else:
            if R == 2:
                result = ()
            else:
                if R + C >= M + 5:
                    result = (R, C, M)
                else:
                    result = ()
        oneclickable_records[R][C][M] = result
    if len(result) > 0 and swaped:
        X, Y, Z = result
        result = (Y, X, Z)
    return result

def get_solution(R, C, M):
    if R * C == M + 1:
        return (1, 1, 0)
    elif R == 1 or C == 1:
        return (R, C, M)
    else:
        return oneclickable(R, C, M)

def get_configuration(R, C, M):
    solution = get_solution(R, C, M)
    if len(solution) == 0:
        #print '----------------------------------------------------------------'
        #print R, C, M
        #print '----------------------------------------------------------------'
        return 'Impossible\n' 
    board = [['*'] * C for i in xrange(R)]
    r, c, m = solution
    for i in xrange(r):
        for j in xrange(c):
            board[i][j] = '.'
    board[0][0] = 'c'
    distance = 0
    count = m
    if R == 1:
        for i in range(m):
            board[0][c - 1 - i] = '*'
    elif C == 1:
        for i in range(m):
            board[r - 1 - i][0] = '*'
    else:
        while count > 0:
            for i in range(distance + 1):
                row = r - 1 - i
                column = c - 1 - (distance - i)
                if count > 0 and row > 1 and column > 1:
                    board[row][column] = '*'
                    count -= 1
            distance += 1
    #if not verify_solution(board):
    #    print '++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
    #    print R, C, M
    #    print '++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
    return '\n'.join([''.join(line) for line in board]) + '\n'

T = int(stdin.readline())

oneclickable_records = rec_dd()

for i in xrange(1, T + 1):
    args = stdin.readline().strip().split(' ')
    R = int(args[0])
    C = int(args[1])
    M = int(args[2])
    result = get_configuration(R, C, M)
    stdout.write('Case #%d:\n%s' % (i, result))