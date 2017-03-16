from __future__ import division
import sys


def print_board(board,R,C):
    result = ""
    for i in xrange(0,R):
        for j in xrange(0,C):
            result += board[i][j]
        result += '\n'
    return result


def check_board(R,C,M):
    # Initialize board
    board = []
    for i in xrange(0,R):
        board.append([])
        for j in xrange(0,C):
            board[i].append('.')
    
    # Handle cases where there is only one empty cell
    if R*C - M == 1:
        for i in xrange(0,R):
            for j in xrange(0,C):
                board[i][j] = '*'
        board[0][0] = 'c'
        return print_board(board,R,C)
    
    # Handle cases where board is one-dimensional
    if R == 1:
        if C - M < 2:
            return "Impossible\n"
        
        for j in xrange(0,M):
            board[0][j] = '*'
        
        board[R-1][C-1] = 'c'
        return print_board(board,R,C)
    
    if C == 1:
        if R - M < 2:
            return "Impossible\n"
        
        for i in xrange(0,M):
            board[i][0] = '*'
        
        board[R-1][C-1] = 'c'
        return print_board(board,R,C)
    
    # Handle cases where the click area can be reduced to a rectangle
    max_R = 0
    max_C = 0
    cells = R * C
    for i in xrange(2,R+1):
        for j in xrange(2,C+1):
            if cells - i * j == M:
                max_R = i
                max_C = j
                break
    
    if max_R != 0:
        for i in xrange(0, R):
            for j in xrange(0, C):
                board[i][j] = '*'
        for i in xrange(0, max_R):
            for j in xrange(0, max_C):
                board[i][j] = '.'
        board[0][0] = 'c'
        return print_board(board,R,C)
    
    # Handle linear fill cases
    if R - (M // C) > 2 and M % C <= C - 2:
        for i in xrange(0, R):
            if M <= 0:
                break
            for j in xrange(0, C):
                if M <= 0:
                    break
                board[i][j] = '*'
                M -= 1
        board[R-1][C-1] = 'c'
        return print_board(board,R,C)
        
    if C - (M // R) > 2 and M % R <= R - 2:
        for j in xrange(0, C):
            if M <= 0:
                break
            for i in xrange(0, R):
                if M <= 0:
                    break
                board[i][j] = '*'
                M -= 1
        board[R-1][C-1] = 'c'
        return print_board(board,R,C)
    
    # Place mines in the R-2 by C-2 section of the board
    for i in xrange(0, R-2):
        if M <= 0:
            break
        for j in xrange(0, C-2):
            if M > 0:
                board[i][j] = '*'
                M -= 1
            else:
                break
    
    if M % 2 == 1 or M > 2*R + 2*C - 8: # M > R*C - (R-2)*(C-2) - 4:
            return "Impossible\n"
    
    for j in xrange(0,C-2):
        if M <= 0:
            break
        for i in xrange(R-2,R):
            board[i][j] = '*'
            M -= 1

    for i in xrange(0,R-2):
        if M <= 0:
            break
        for j in xrange(C-2,C):
            board[i][j] = '*'
            M -= 1
    
    board[R-1][C-1] = 'c'
    return print_board(board,R,C)


def main():
    file = open(sys.argv[1], 'r')
    T = int(file.readline().strip())
    
    for trial in xrange(1,T+1):
        sys.stdout.write("Case #%d:\n" % trial)
        
        data = file.readline().strip().split()
        R = int(data[0])
        C = int(data[1])
        M = int(data[2])
        
        sys.stdout.write(check_board(R,C,M))
        

if __name__ == '__main__':
    main()