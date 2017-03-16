for t in range(int(raw_input())):
    board = []
    size = 4
    for i in range(size):
        board.append(list(raw_input()))
    raw_input()
    
    status = "not found"
    
    #check rows for a winner
    for row in board:
        if row.count('X') + row.count('T') == size:
            status = "X won"
            break
        if row.count('O') + row.count('T') == size:
            status = "O won"
            break
    
    #if no winner found, check columns for a winner by transposing the board
    if status == "not found":
        board = [[row[i] for row in board] for i in range(size)]
        for row in board:
            if row.count('X') + row.count('T') == size:
                status = "X won"
                break
            if row.count('O') + row.count('T') == size: 
                status = "O won"
                break
    
    #if no winner found, check diagonals for a winner
    if status == "not found":
        diagonal = [board[0][0], board[1][1], board[2][2], board[3][3]]
        if diagonal.count('X') + diagonal.count('T') == size:
            status = "X won"
        if diagonal.count('O') + diagonal.count('T') == size:
            status = "O won"
        diagonal = [board[0][3], board[1][2], board[2][1], board[3][0]]
        if diagonal.count('X') + diagonal.count('T') == size:
            status = "X won"
        if diagonal.count('O') + diagonal.count('T') == size:
            status = "O won"
    
    if status == "not found":
        for row in board:
            if row.count('.') > 0:
                status = "Game has not completed"
        if status == "not found": status = "Draw"
    
    print "Case #%d: %s" % (t+1, status)
