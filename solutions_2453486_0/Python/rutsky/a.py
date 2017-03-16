import sys
import fileinput
import itertools

def count_symbols(board):
    b = list(itertools.chain(*board))
    return b.count("X"), b.count("O"), b.count(".")

def is_won(board, symbol):
    for row in board:
        if row.count(symbol) + row.count("T") == 4:
            return True
    
    board_t = map(list, zip(*board))
    
    for row in board_t:
        if row.count(symbol) + row.count("T") == 4:
            return True
    
    if len([1 for i in xrange(4) if board[i][i] in [symbol, "T"]]) == 4:
        return True
    
    if len([1 for i in xrange(4) if board[3 - i][i] in [symbol, "T"]]) == 4:
        return True
    
    return False

def solve(board):
    x, o, empty = count_symbols(board)
    
    if x > o:
        if is_won(board, "X"):
            return "X won"
    else:
        assert x == o
        if is_won(board, "O"):
            return "O won"
    if empty == 0:
        return "Draw"
    else:
        return "Game has not completed"

def main():
    fin = fileinput.input()
    fout = sys.stdout
    
    T = int(fin.readline())
    
    for case_idx in xrange(T):
        board = [list(fin.readline().strip()) for r in xrange(4)]
        fin.readline()  # empty line
        #print board
        
        result = solve(board)
        
        fout.write("Case #{0}: {1}\n".format(case_idx + 1, result))
    
if __name__ == "__main__":
    main()    
