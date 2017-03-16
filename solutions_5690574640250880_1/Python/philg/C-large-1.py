#!/usr/bin/python

import sys

PROBLEMSIZE=int(sys.stdin.readline())

for t in range(PROBLEMSIZE):
    r, c, m= [int(num) for num in sys.stdin.readline().split(" ")]
    freeFields = (r*c-m)
    board = [list('*'*c) for row in range(r)]
    neighbors = [(0,0)]
    for i in range(freeFields):
        row, col = neighbors[i]
        board[row][col] = "."

        for neig in [(0,1),(1,0),(1,1)]:
            row_,col_ = neig
            if (row_+row, col_+col) not in neighbors:
                if (row_+row < r) and (col_+col < c):
                    neighbors.append((row_+row, col_+col))
    board[0][0] = "c"
    print("Case #%s:"%str(t+1))
    sys.stderr.write("%s %s %s\n" % (r, c, m) )
    if (c == 1) or (r == 1) or (freeFields == 1):
        for row in range(r):
            print("".join(board[row]))
    else:
        ro,co = neighbors[freeFields-1]
        if (co == 0) or (ro == 0):
            if (neighbors[freeFields-2][0] > 1) and (neighbors[freeFields-2][1] > 1):
# move mine from old to new / ugly fix
                old_row, old_col = neighbors[freeFields]
                new_row, new_col = neighbors[freeFields-2]
                board[old_row][old_col] = "."
                board[new_row][new_col] = "*"
                for row in range(r):
                    print("".join(board[row]))
            else:
                print("Impossible")
                for row in range(r):
                    sys.stderr.write("".join(board[row]))
                    sys.stderr.write("\n")
        elif (ro == 0):
            print("Impossible")
            for row in range(r):
                sys.stderr.write("".join(board[row]))
                sys.stderr.write("\n")
        else:
            for row in range(r):
                print("".join(board[row]))
