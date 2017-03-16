N = 4

tests = int(raw_input().strip())
for test in xrange(tests):
    board = []
    for i in xrange(N):
        board.append(raw_input().strip())
    raw_input()
    xwin = False
    ywin = False
    empty = False
    option = {
        'X': (True, False),
        'O': (False, True),
        '.': (False, False),
        'T': (True, True)
        }
    for i in xrange(N):
        x = True
        y = True
        for j in xrange(N):
            x = (x & option[board[i][j]][0])
            y = (y & option[board[i][j]][1])
        xwin = (xwin | x)
        ywin = (ywin | y)
        x = True
        y = True
        for j in xrange(N):
            x = (x & option[board[j][i]][0])
            y = (y & option[board[j][i]][1])
        xwin = (xwin | x)
        ywin = (ywin | y)
    x = True
    y = True
    for j in xrange(N):
        x = (x & option[board[j][j]][0])
        y = (y & option[board[j][j]][1])
    xwin = (xwin | x)
    ywin = (ywin | y)
    x = True
    y = True
    for j in xrange(N):
        x = (x & option[board[N - 1 - j][j]][0])
        y = (y & option[board[N - 1 - j][j]][1])
    xwin = (xwin | x)
    ywin = (ywin | y)
    for i in xrange(N):
        for j in xrange(N):
            empty = (empty|(board[i][j]=='.'))
    if xwin and ywin:
        print 'Case #' + str(test + 1) + ': Draw'
    elif xwin:
        print 'Case #' + str(test + 1) + ': X won'
    elif ywin:
        print 'Case #' + str(test + 1) + ': O won'
    elif empty:
        print 'Case #' + str(test + 1) + ': Game has not completed'
    else:
        print 'Case #' + str(test + 1) + ': Draw'
