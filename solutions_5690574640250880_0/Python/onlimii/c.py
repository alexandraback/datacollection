#!/usr/bin/env python

def draw(board, f, t):
    if t:
        for row in board:
            for col in row:
                f.write(col)
            f.write("\n")
    else:
        temp = zip(*board)
        for row in temp:
            for col in row:
                f.write(col)
            f.write("\n")

with open("C-small-attempt7.in", "r") as fin:
    cases = int(fin.readline())
    fout = open("C-small-attempt7.out", "w")

# -1 for mine, 0 for nothing, 1 for blocks
    for i in xrange(cases):
        R, C, mine = map(int, fin.readline().split())
        tranverse = True
        if R < C:
            R, C = C, R
            tranverse = False
        board = []
        # init board
        for _ in xrange(R):
            board.append(['.'] * C)

        if mine >= R * C:
            fout.write("Case #%d:\nImpossible\n" % (i + 1))
        elif mine == R *C -1:
            for n in xrange(R):
                for p in xrange(C):
                    board[n][p] = '*'
            board[R-1][C-1] = 'c'
            fout.write("Case #%d:\n" % (i + 1))
            draw(board, fout, tranverse)
        elif C == 1 or R == 1:
            if R * C - mine < 1:
                fout.write("Case #%d:\nImpossible\n" % (i + 1))
            else:
                for n in xrange(mine):
                    if C == 1:
                        board[n][0] = '*'
                    else:
                        board[0][n] = '*'
                if C == 1:
                    board[R - 1][0] = 'c'
                else:
                    board[0][C-1] = 'c'
                fout.write("Case #%d:\n" % (i + 1))
                draw(board, fout, tranverse)
        elif C == 2 or R == 2:
            if mine % 2 == 1:
                fout.write("Case #%d:\nImpossible\n" % (i + 1))
            elif R * C - mine < 4:
                fout.write("Case #%d:\nImpossible\n" % (i + 1))
            else:
                for n in xrange(mine / 2):
                    if C == 2:
                        board[n][0] = board[n][1] = '*'
                    else:
                        board[0][n] = board[1][n] = '*'
                board[R - 1][C - 1] = 'c'
                fout.write("Case #%d:\n" % (i + 1))
                draw(board, fout, tranverse)
        elif C == 3 or R == 3:
            if R * C - mine < 6:
                if R*C-mine == 4:
                    for n in xrange(R):
                        for p in xrange(C):
                            board[n][p] = '*'
                    board[R-1][C-1] = 'c'
                    board[R-2][C-1] = board[R-2][C-2] = board[R-1][C-2] = '.'
                    fout.write("Case #%d:\n" % (i + 1))
                    draw(board, fout, tranverse)
                else:
                    fout.write("Case #%d:\nImpossible\n" % (i + 1))
            elif mine % 3 == 0:
                for n in xrange(mine / 3):
                    if C == 3:
                        board[n][0] = board[n][1] = board[n][2] = '*'
                    else:
                        board[0][n] = board[1][n] = board[2][n] = '*'
                board[R - 1][C - 1] = 'c'
                fout.write("Case #%d:\n" % (i + 1))
                draw(board, fout, tranverse)
            elif mine % 3 == 1:
                for n in xrange(mine / 3):
                    if C == 3:
                        board[n][0] = board[n][1] = board[n][2] = '*'

                    else:
                        board[0][n] = board[1][n] = board[2][n] = '*'

                if C == 3:
                    board[mine / 3][0] = '*'
                    board[R - 1][C - 1] = 'c'
                else:
                    board[0][mine/3] = '*'
                    board[R - 1][C - 1] = 'c'
                fout.write("Case #%d:\n" % (i + 1))
                draw(board, fout, tranverse)
            elif mine % 3 == 2:
                if (R - mine / 3 <= 3 and C == 3) or (C - mine / 3 <= 3 and R == 3):
                    fout.write("Case #%d:\nImpossible\n" % (i + 1))
                else:
                    for n in xrange(mine / 3):
                        if C == 3:
                            board[n][0] = board[n][1] = board[n][2] = '*'

                        else:
                            board[0][n] = board[1][n] = board[2][n] = '*'

                    if C == 3:
                        board[mine / 3][0] = '*'
                        board[mine / 3 + 1][0] = '*'
                        board[R - 1][C - 1] = 'c'
                    else:
                        board[0][mine / 3] = '*'
                        board[0][mine / 3 + 1] = '*'
                        board[R - 1][C - 1] = 'c'
                    fout.write("Case #%d:\n" % (i + 1))
                    draw(board, fout, tranverse)
        else:
            if R*C - mine >= 2 * C:
                if (R*C-mine) % C != 1:
                    for n in xrange(mine / C):
                        for p in xrange(C):
                            board[n][p] = '*'
                    for n in xrange(mine % C):
                        board[mine/C][n] = '*'
                    board[R-1][C-1] = 'c'
                    fout.write("Case #%d:\n" % (i + 1))
                    draw(board, fout, tranverse)
                else:
                    for n in xrange(mine / C):
                        for p in xrange(C):
                            board[n][p] = '*'
                    for n in xrange(C-3):
                        board[mine/C][n] = '*'
                    board[mine/C+1][0] = '*'
                    if mine/C+2 == R-2:
                        board[mine/C][C-3] = '*'
                    else:
                        board[mine/C+2][0] = '*'
                    board[R-1][C-1] = 'c'
                    fout.write("Case #%d:\n" % (i + 1))
                    draw(board, fout, tranverse)
            else:
                remain = mine-(R-2)*C
                if R*C - mine < 4:
                    fout.write("Case #%d:\nImpossible\n" % (i + 1))
                else:
                    if remain % 2 == 0:
                        for n in xrange(R-2):
                            for p in xrange(C):
                                board[n][p] = '*'
                        for p in xrange(remain / 2):
                            board[R-2][p] = '*'
                            board[R-1][p] = '*'
                        board[R-1][C-1] = 'c'
                        fout.write("Case #%d:\n" % (i + 1))
                        draw(board, fout, tranverse)
                    elif R*C-mine < 9:
                        fout.write("Case #%d:\nImpossible\n" % (i + 1))
                    else:
                        for n in xrange(R-3):
                            for p in xrange(C):
                                board[n][p] = '*'
                        for n in xrange(C-3):
                            board[R-3][n] = '*'
                        remain += 3
                        for p in xrange(remain / 2):
                            board[R-2][p] = '*'
                            board[R-1][p] = '*'
                        board[R-1][C-1] = 'c'
                        fout.write("Case #%d:\n" % (i + 1))
                        draw(board, fout, tranverse)
