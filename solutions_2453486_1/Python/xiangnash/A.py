import sys

def countTik(board, rows, cols):
    nx = sum([1 if board[rows[i]][cols[i]] == 'X' or board[rows[i]][cols[i]] == 'T' else 0 for i in range(4)])
    no = sum([1 if board[rows[i]][cols[i]] == 'O' or board[rows[i]][cols[i]] == 'T' else 0 for i in range(4)])
    ne = sum([1 if board[rows[i]][cols[i]] == '.' else 0 for i in range(4)])
    return nx, no, ne

def check(board, rows, cols):
    nx, no, ne = countTik(board, rows, cols)
    #print nx, no, ne
    xwin = False
    owin = False
    isComplete = True
    if nx == 4:
        xwin = True
    if no == 4:
        owin = True
    if ne > 0:
        isComplete = False
    return xwin, owin, isComplete
    
T = int(sys.stdin.readline())
for ca in xrange(1, T+1):
    board = []
    if ca > 1:
        sys.stdin.readline()
    for row in xrange(4):
        board.append([v for v in sys.stdin.readline()[:-1]])
    
    #print board
    
    xwon = False
    owon = False
    isCompleted = True
    for i in range(4):
        rows = [i for j in range(4)]
        cols = [j for j in range(4)]
        xwin, owin, isComplete = check(board, rows, cols)
        xwon |= xwin
        owon |= owin
        isCompleted &= isComplete
        xwin, owin, isComplete = check(board, cols, rows)
        xwon |= xwin
        owon |= owin
        isCompleted &= isComplete
    rows = [i for i in range(4)]
    cols = [i for i in range(4)]
    xwin, owin, isComplete = check(board, rows, cols)
    xwon |= xwin
    owon |= owin
    isCompleted &= isComplete
    rows = [i for i in range(4)]
    cols = [3-i for i in range(4)]
    xwin, owin, isComplete = check(board, rows, cols)
    xwon |= xwin
    owon |= owin
    isCompleted &= isComplete
    
    #print xwon, owon, isCompleted
    
    print "Case #%d:" % (ca), 
    if xwon:
        print "X won"
    elif owon:
        print "O won"
    elif isCompleted:
        print "Draw"
    else:
        print "Game has not completed"
