#!/usr/bin/python

"""Usage:
    X.py < X.in > X.out
"""

################################################################################
# util functions

logging = False

globalCase = 0
def log(string="", case=0):
    global globalCase
    if logging:
        if case > 0:
            globalCase = case
            string = "started case - %s" % string
        print("Case #%d: %s" % (globalCase, string))

################################################################################
# problem functions

def solve(rows, cols, mines):
    log("rows={}, cols={}, mines={}".format(rows, cols, mines))
    
    board = ""
    boardsize = rows * cols
    freecells = boardsize - mines

    # if one of the dimension is 1, it's always possible
    if rows==1 or cols==1:
        for r in range(rows):
            board += "\n"
            for c in range(cols):
                if mines > 0:
                    board += "*"
                    mines -= 1
                else:
                    board += "."
        return board[:-1]+"c"

    # special case: only one cell is free
    if freecells == 1:
        board = ("\n" + ("*"*cols))*rows
        return board[:-1]+"c"

    # if one of the dimension is 2, it's possible only if mines ar even
    if (rows==2 or cols==2) and ((mines%2) == 1):
        return "\nImpossible"

    # special case, always impossible if 5 cells free
    if freecells == 5:
        return "\nImpossible"

    # if the free cells are 2 or 3
    if freecells < 4:
        return "\nImpossible"

    # general purpose paint board
    for r in range(rows):
        if mines == 0:
            board += "\n" + ("."*cols)
        elif rows-r == 2 and mines%2==1:
            return "\nImpossible"
        else:
            x = mines/(rows-r)
            if mines%(rows-r)==0 and x<(cols-2):
                board += "\n" + ("*"*x) + ("."*(cols-x))
                mines -= x
            else:
                if mines == cols-1:
                    if rows-r == 3:
                        if mines == 2:
                            return "\nImpossible"
                        else:
                            board += "\n" + ("*"*(mines-2)) + "..."
                            mines = 2
                    else:
                        board += "\n" + ("*"*(mines-1)) + ".."
                        mines = 1
                elif mines >= cols:
                    # preserve last 4 cells
                    plc = cols if rows-r>2 else cols-2
                    board += "\n" + ("*"*plc) + ("."*(cols-plc))
                    mines -= plc
                else:
                    board += "\n" + ("*"*mines) + ("."*(cols-mines))
                    mines = 0

    return board[:-1]+"c"
    
    
################################################################################
# main

if __name__ == '__main__':
    import sys
    r = sys.stdin.readline
    cases = int(r())
    for c in xrange(cases):
        log(case=c+1)
        #single = int(r())
        (R, C, M) = map(int, r().split())
        print 'Case #{}:{}'.format(c + 1, solve(R, C, M))
