def if_win(b, ch):
    for i in range(4):
        ok = True
        for j in range(4):
            if b[i][j] != ch:
                ok = False
                break
        if ok:
            return True

        ok = True
        for j in range(4):
            if b[j][i] != ch:
                ok = False
                break
        if ok:
            return True

    ok = True
    for i in range(4):
        if b[i][i] != ch:
            ok = False
            break
    if ok:
        return True

    ok = True
    for i in range(4):
        if b[i][3 - i] != ch:
            ok = False
            break
    if ok:
        return True

    return False

fi = open('A2.in', 'r')
fo = open('A2.out', 'w')

case = int(fi.readline())
for icase in range(case):
    board = []
    for i in range(4):
        line = fi.readline()
        board.append([])
        for j in range(4):
            board[i].append(line[j])
    fi.readline()

    ti = tj = -1
    not_finish = False
    for i in range(4):
        for j in range(4):
            if board[i][j] == 'T':
                ti = i
                tj = j
            if board[i][j] == '.':
                not_finish = True

    if ti > -1:
        board[ti][tj] = 'X'
    xwin = if_win(board, 'X')
    if ti > -1:
        board[ti][tj] = 'O'
    owin = if_win(board, 'O')

    if xwin:
        ans_str = 'X won'
    elif owin:
        ans_str = 'O won'
    elif not_finish:
        ans_str = 'Game has not completed'
    else:
        ans_str = 'Draw'
    fo.write('Case #%d: %s\n' % (icase + 1, ans_str))

fi.close()
fo.close()
