n = int(input())
for i in range(0, n):
    board = [input(), input(), input(), input()]
    input()
    going, xWon, oWon = False, False, False
    for j in range(0,4):
        going = True if '.' in board[j] else (False and going)
        row = board[j]
        col = set(board[k][j] for k in range(0,4))
        if not ('.' in row or 'O' in row):
            xWon = True
        elif not ('.' in row or 'X' in row):
            oWon = True
        if not ('.' in col or 'O' in col):
            xWon = True
        elif not ('.' in col or 'X' in col):
            oWon = True

    if not (xWon or oWon):
        diag1 = set(board[j][j] for j in range(0,4))
        diag2 = set(board[j][3-j] for j in range(0,4))
        if not ('.' in diag1 or 'O' in diag1):
            xWon = True
        elif not ('.' in diag1 or 'X' in diag1):
            oWon = True
        if not ('.' in diag2 or 'O' in diag2):
            xWon = True
        elif not ('.' in diag2 or 'X' in diag2):
            oWon = True

    if xWon:
        print("Case #%d: X won" % (i+1))
    elif oWon:
        print("Case #%d: O won" % (i+1))
    elif not going:
        print("Case #%d: Draw" % (i+1))
    else:
        print("Case #%d: Game has not completed" % (i+1))
