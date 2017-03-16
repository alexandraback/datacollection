BOARD_SIZE = 4
RESPONSES = ("X won", "O won", "Draw", "Game has not completed")

n = int(input())

def isX(c):
    return c in "XT"

def isO(c):
    return c in "OT"

def isSomething(c):
   return c in "XOT"

def getResponse(board):
    full = True
    for row in board:
        if all(map(isX, row)):
            return 0
        if all(map(isO, row)):
            return 1
        if full:
            if not all(map(isSomething, row)):
                full = False
    transpose = zip(*board)
    for col in transpose:
        if all(map(isX, col)):
            return 0
        if all(map(isO, col)):
            return 1
    diag = (
        [board[i][i] for i in range(BOARD_SIZE)],
        [board[i][BOARD_SIZE-i-1] for i in range(BOARD_SIZE)])
    for i in range(2):
        if all(map(isX, diag[i])):
            return 0
        if all(map(isO, diag[i])):
            return 1
    if full:
        return 2
    else:
        return 3


for i in range(n):
    board = []
    for y in range(BOARD_SIZE):
        board.append(list(input()))
    input()
    response = getResponse(board)
    print("Case #{}: {}".format(i+1, RESPONSES[response]))
