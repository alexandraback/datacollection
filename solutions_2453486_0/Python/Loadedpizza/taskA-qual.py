# Problem A: Tic-Tac-Toe-Tomek
# Determine the state of the 4x4 game.

inputFile = open('A-small-attempt1.in', 'rU')
outputFile = open('A-small-attempt1.out', 'w')


def win(player, board): # replace player with either 'X' or 'O'
    if player == 'X':
        winningStates = ['XXXX', 'TXXX', 'XTXX', 'XXTX', 'XXXT']
    else: # player == 'O'
        winningStates = ['OOOO', 'TOOO', 'OTOO', 'OOTO', 'OOOT']

    possible = [] # each row, coln, diagonal
    for row in xrange(4): # rows
        possible.append(''.join(board[row]))
    for x in xrange(4): # columns
        col = board[0][x] + board[1][x] + board[2][x] + board[3][x]
        possible.append(col) # col should be a string
    # diagonals are [0][0]+[1][1]+[2][2]+[3][3],
    # or [0][3],[1][2],[2][1],[3][0]
    possible.append(board[0][0] + board[1][1] + board[2][2] + board[3][3])
    possible.append(board[0][3] + board[1][2] + board[2][1] + board[3][0])

    # possible now generated, should have 10 entries
    # check if any of the winning lines are in possible
    for line in winningStates:
        if line in possible:
            return True
    return False


def unfinished(board): # test if there are any empty spots '.' left
    for row in board:
        if '.' in row:
            return True
    return False


## main function, keep global for easy debug
cases = int(inputFile.readline())
for current in xrange(1, cases + 1):
    board = []
    for x in xrange(4): # [0,1,2,3]
        line = inputFile.readline().strip()
        board.append(list(line)) # makes more sense that ['X..T']
    # board is now the 4x4 matrix of the game, board[row][col]
    inputFile.readline() # get rid of the empty line

    debug = [''.join(x) for x in board] # debug
    for food in debug:
        print food
    

    if win('X', board) and win('O', board):
        raise('You failed, board with both winning?') # strictly debug

    if win('X', board):
        message = 'X won'
    elif win('O', board):
        message = 'O won'
    else: # no wins
        if unfinished(board):
            message = 'Game has not completed'
        else:
            message = 'Draw'

    # output time
    print "Case #%d: %s" % (current, message)
    outputFile.write("Case #%d: %s\n" % (current, message))
    # remember to add \n when using outputFile.write()

inputFile.close()
outputFile.close()
