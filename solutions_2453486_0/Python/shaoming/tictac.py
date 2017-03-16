#!/usr/bin/env python

import sys, os, re

#---------------------------------------------------
# Variable 
#---------------------------------------------------

#---------------------------------------------------
# Function 
#---------------------------------------------------
def check_line(line):
    if '.' in line:
        return None 
    if 'X' in line:
        if 'O' in line:
            return None
        else:
            return 'X'
    else:
        if 'O' in line:
            return 'O' 
        else:
            return None 

def get_line(board):
    for i in range(4): yield board[i]
    for i in range(4): yield ''.join([ board[j][i] for j in range(4)]) 
    yield ''.join([board[i][i] for i in range(4)])
    yield ''.join([board[i][3-i] for i in range(4)])
    return

def check_tic(board):
    for row in get_line(board):
        result = check_line(row)
        if None != result: 
            return result
    for i in range(4):
        if '.' in board[i]:
            return None
    return 'D' 

def load_file(filename):
    dict = {'X':'X won', 'O': 'O won', None:'Game has not completed', 'D':'Draw'}
    with open(filename, 'rU') as f:
        number = int(f.readline())
        for i in range(number):
            board = [] 
            for j in range(4): board.append(f.readline().strip())
            f.readline()
            result = check_tic(board)
            print 'Case #%d: %s' % (i+1, dict[result])
    return

#---------------------------------------------------
# Entry Point 
#---------------------------------------------------
def main():
    load_file (sys.argv[1])

    return

#---------------------------------------------------
# Unit Test Entry 
#---------------------------------------------------
if __name__ == '__main__':
    main()


