# Tic Tac Toe Tomek: tictactoe

import re
import sys

def tictactoe(filename):
    running = 'Game has not completed'
    draw = 'Draw'
    def check_eq(a, b, c, d):
        symb = a
        if a == 'T':
            symb = d
        if symb == '.':
            return None
        if (a == 'T' or a == symb) and (b == 'T' or b == symb) and (c == 'T' or c == symb) and (d == 'T' or d == symb):
            return symb
        return None
    def check(board):
        finished = True
        for i in range(len(board)):
            symb = check_eq(board[i][0], board[i][1], board[i][2], board[i][3])            
            if symb is not None:
                return symb + ' won'
            symb = check_eq(board[0][i], board[1][i], board[2][i], board[3][i])
            if symb is not None:
                return symb + ' won'
        symb = check_eq(board[0][0], board[1][1], board[2][2], board[3][3])
        if symb is not None:
            return symb + ' won'
        symb = check_eq(board[3][0], board[2][1], board[1][2], board[0][3])
        if symb is not None:
            return symb + ' won'
        if '.' in ''.join(board):
            return running
        else:
            return draw
            
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in range(total):
            board = []
            for j in range(4): 
                board.append(f_in.readline()[:4])
            print 'Case #{0}: {1}'.format(i+1, check(board))
            f_in.readline()
            
if __name__ == "__main__":
    cs = sys.argv
    fun = globals()[cs[1]]
    fun(cs[2])
    
