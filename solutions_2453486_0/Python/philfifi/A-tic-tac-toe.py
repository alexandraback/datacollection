#!/usr/bin/python2

"""
  Google Code Jam 2013
  Philfifi  --  http://www.pluc.fr
  All rigths reserved
"""

from math import sqrt
from decimal import *
getcontext().prec = 100

#import psyco
#psyco.full()

_debug = 0





lines_o_won = set(["OOOO",
                   "TOOO",
                   "OTOO",
                   "OOTO",
                   "OOOT"])

lines_x_won = set(["XXXX",
                   "TXXX",
                   "XTXX",
                   "XXTX",
                   "XXXT"])

def solve_case(case_no,  board ):
    print "-------------- New case", case_no
    print "board", board


    x_won = "X won"
    draw = "Draw"
    not_comp = "Game has not completed"
    o_won = "O won"

    dots_detected = False

    for line in board:
        if line in lines_o_won:
            return o_won
        elif line in lines_x_won:
            return x_won
        elif "." in line:
            dots_detected = True

    # Test colums
    for i in range(4):
        col = board[0][i] + board[1][i] + board[2][i] + board[3][i]
        if col in lines_o_won:
            return o_won
        elif col in lines_x_won:
            return x_won

    # Test diag
    diag1 = board[0][0] + board[1][1] + board[2][2] + board[3][3]
    if diag1 in lines_o_won:
        return o_won
    elif diag1 in lines_x_won:
        return x_won

    diag2 = board[0][3] + board[1][2] + board[2][1] + board[3][0]
    if diag2 in lines_o_won:
        return o_won
    elif diag2 in lines_x_won:
        return x_won

    if dots_detected:
        return not_comp
    else:
        return draw


def main(argv):

    f_out_name = argv[1].split(".")[0] + ".out"
    f_out = open(f_out_name, "w")

    fd = open(argv[1])
    nb_cases = int(fd.readline())


    for case_no in range(1, nb_cases+1):
        board = [fd.readline().strip(),
                 fd.readline().strip(),
                 fd.readline().strip(),
                 fd.readline().strip(),
                 ]

        fd.readline() # empty line

        # Have read all stuff for this case:
        f_out.write( "Case #%d: %s\n" % (case_no,
                                         solve_case(case_no, board)
                                         )
                     )
        f_out.flush()

    f_out.close()

    for line in open(f_out_name):
        print line,



import sys
if __name__ == "__main__":
    main(sys.argv)
