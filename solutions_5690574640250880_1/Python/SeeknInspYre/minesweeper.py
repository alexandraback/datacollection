__author__ = 'Shailesh'

def writeBoard(board, output):
    output.write("\n".join("".join(line) for line in board))
    output.write("\n")

with open("../files/C-large.in", 'r') as input, open("../files/output.txt", 'w') as output:
    t = int(input.readline())
    for i in xrange(t):
        output.write("Case #" + str(i+1) + ":\n")
        r, c, m = map(int, input.readline().split())
        if m == 0:
            board = [['.']*c for i in xrange(r)]
            board[0][0] = 'c'
            writeBoard(board, output)
            continue
        if r == 1 or c == 1:
            board = [['.']*c for i in xrange(r)]
            board[r-1][c-1] = 'c'
            if r == 1:
                for j in xrange(m):
                    board[0][j] = "*"
                writeBoard(board, output)
                continue
            # c == 1
            for j in xrange(m):
                board[j][0] = "*"
            writeBoard(board, output)
            continue
        rem = r*c - m
        if rem in {2, 3, 5, 7}:
            output.write("Impossible\n")
            continue
        odd = not rem % 2 == 0
        board = [['*']*c for i in xrange(r)]
        if rem == 1:
            board[0][0] = 'c'
            writeBoard(board, output)
            continue

        if r == 2 or c == 2 or rem in {4, 6}:
            if odd:
                output.write("Impossible\n")
                continue
            if r == 2:
                for j in xrange(rem/2):
                    board[0][j] = '.'
                    board[1][j] = '.'
            else:
                for j in xrange(rem/2):
                    board[j][0] = '.'
                    board[j][1] = '.'
            board[0][0] = 'c'
            writeBoard(board, output)
            continue

        # r >= 3 and c >= 3 and rem >= 8, means guaranteed solution
        for j in xrange(3):
            for k in xrange(3):
                board[j][k] = '.'
        board[0][0] = 'c'
        board[2][2] = '*'
        rem -= 8
        doubles = rem/2
        if c-3 >= doubles:
            for j in xrange(3, 3+doubles):
                board[0][j] = '.'
                board[1][j] = '.'
            if odd:
                board[2][2] = '.'
            writeBoard(board, output)
            continue
        for j in xrange(3, c):
            board[0][j] = '.'
            board[1][j] = '.'
        doubles -= c - 3
        rem -= (c - 3) * 2
        if r-3 >= doubles:
            for j in xrange(3, 3+doubles):
                board[j][0] = '.'
                board[j][1] = '.'
            if odd:
                board[2][2] = '.'
            writeBoard(board, output)
            continue
        for j in xrange(3, r):
            board[j][0] = '.'
            board[j][1] = '.'
        doubles -= r - 3
        rem -= (r - 3) * 2
        for j in xrange(2, r):
            for k in xrange(2, c):
                if rem == 0:
                    break
                board[j][k] = '.'
                rem -= 1
            else:
                continue
            break
        writeBoard(board, output)

