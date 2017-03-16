import sys

#index by row then column
def readboard(f):
    board = []
    for row in range(4):
        line = []
        for c in f.readline():
            if c in ['X', 'O', 'T', '.']:
                line.append(c)
        board.append(line)
    f.readline()
    return board

def isequaltochar(c, other):
    return c == other or 'T' == other
    
def checkforwin(board, c):
    for row in range(4):
        equal = True
        for col in range(4):
            if not isequaltochar(c, board[row][col]):
                equal = False
                break
        if equal:
            return True
    
    for col in range(4):
        equal = True
        for row in range(4):
            if not isequaltochar(c, board[row][col]):
                equal = False
                break
        if equal:
            return True
            
    if isequaltochar(c, board[0][0]) and isequaltochar(c, board[1][1]) and isequaltochar(c, board[2][2]) and isequaltochar(c, board[3][3]):
        return True
        
    if isequaltochar(c, board[0][3]) and isequaltochar(c, board[1][2]) and isequaltochar(c, board[2][1]) and isequaltochar(c, board[3][0]):
        return True
        
    return False
        
    
def checkforemptyspace(board):
    for row in board:
        for c in row:
            if c == '.':
                return True
    return False

if __name__=="__main__":
    filename = sys.argv[1]
    f = open(filename, 'r')
    numtests = int(f.readline())
    for i in range(1, numtests+1):
        board = readboard(f)
        if checkforwin(board, 'X'):
            print "Case #" + str(i) + ": X won"
        elif checkforwin(board, 'O'):
            print "Case #" + str(i) + ": O won"
        elif checkforemptyspace(board):
            print "Case #" + str(i) + ": Game has not completed"
        else:
            print "Case #" + str(i) + ": Draw"