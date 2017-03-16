def solve_case(board):
    for row in xrange(4):
        for col in xrange(4):
            if board[row][col] == "X":
                board[row][col] = 100
            elif board[row][col] == "O":
                board[row][col] = -100
            elif board[row][col] == "T":
                board[row][col] = 50
            else:
                board[row][col] = 0
    result = None
    for row in board:
        s = sum(row)
        if s == 400 or s == 350:
            result = "X won"
            break
        elif s == -400 or s == -250:
            result = "O won"
            break
    if result == None:
        for col in xrange(4):
            s = 0
            for row in xrange(4):
                s += board[row][col]
            if s == 400 or s == 350:
                result = "X won"
                break
            elif s == -400 or s == -250:
                result = "O won"
                break
    if result == None:
        s = board[0][0] + board[1][1] + board[2][2] + board[3][3]
        if s == 400 or s == 350:
            result = "X won"
        elif s == -400 or s == -250:
            result = "O won"
     
    if result == None:
        s = board[0][3] + board[1][2] + board[2][1] + board[3][0]
        if s == 400 or s == 350:
            result = "X won"
        elif s == -400 or s == -250:
            result = "O won"     
    
    if result == None:
        isDraw = True
        for row in xrange(4):
            for col in xrange(4):
                if board[row][col] == 0:
                    isDraw = False
                    break
            if isDraw == False:
                break
        
        if isDraw:
            result = "Draw"
        else:
            result = "Game has not completed"
            
    
    return result
        

def solve_cases(fin, fout):
    nCases = int(fin.readline().strip())
    for i in xrange(nCases):
        # get case
        board = []
        for j in xrange(4):
            board.append(list(fin.readline().strip()))
        empty = fin.readline()
        # solve case
        result = solve_case(board)
        fout.write("Case #%d: %s\n"%(i+1, result))
        print "Case #%d: %s\n"%(i+1, result)

from sys import argv
solve_cases(open(argv[1]), open(argv[1].replace("in", "out"), "w"))
