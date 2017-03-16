def is_winning(board):
    # rows
    new_board = board[0:]
    # columns
    for i in range(4):
        new_board.append(board[0][i] + board[1][i] + board[2][i] + board[3][i])
    # diagonals
    new_board.append(board[0][0] + board[1][1] + board[2][2] + board[3][3])
    new_board.append(board[0][3] + board[1][2] + board[2][1] + board[3][0])
    # check
    incomplete = False
    for path in new_board:
        if path.count('.') > 0:
            incomplete = True
        if path.count('O') == 4 or (path.count('O') == 3 and path.count('T') == 1):
            return 'O won'
        if path.count('X') == 4 or (path.count('X') == 3 and path.count('T') == 1):
            return 'X won'
    if incomplete:
        return 'Game has not completed'
    else:
        return 'Draw'

cases = int(raw_input())
for c in xrange(cases):
    rows = []
    for i in range(4):
        rows.append(raw_input())
    raw_input()
    print "Case #%d: %s" % ((c+1), is_winning(rows))
    
