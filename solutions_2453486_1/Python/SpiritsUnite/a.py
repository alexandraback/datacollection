import sys

n = int(raw_input())
for i in xrange(n):
    winner = ''
    grid = [raw_input() for j in xrange(4)]
    comp = True
    for k in xrange(2):
        check = ''
        for j in xrange(4):
            if k == 0:
                check = grid[j]
            elif k == 1:
                check = ''.join(l[j] for l in grid)
            if '.' in check:
                comp = False
            elif 'X' in check and 'O' not in check:
                winner = 'X'
            elif 'O' in check and 'X' not in check:
                winner = 'O'
            if winner != '':
                break
        if winner != '':
            break
    if winner == '':
        check = ''.join(grid[j][j] for j in xrange(4))
        if '.' in check:
            comp = False
        elif 'X' in check and 'O' not in check:
            winner = 'X'
        elif 'O' in check and 'X' not in check:
            winner = 'O'
    if winner == '':
        check = ''.join(grid[j][3 - j] for j in xrange(4))
        if '.' in check:
            comp = False
        elif 'X' in check and 'O' not in check:
            winner = 'X'
        elif 'O' in check and 'X' not in check:
            winner = 'O'

    sys.stdout.write("Case #%d: " % (i + 1))
    if winner != '':
        print winner + " won"
    elif comp:
        print "Draw"
    else:
        print "Game has not completed"
    raw_input()

