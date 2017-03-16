def check(board, winner):
    seqs = []
    for i in range(4):
        seq = ''
        for j in range(4):
            seq += board[i][j]
        seqs.append(seq)
    for i in range(4):
        seq = ''
        for j in range(4):
            seq += board[j][i]
        seqs.append(seq)
    seq = ''
    for i in range(4):
        seq += board[i][i]
    seqs.append(seq)
    seq = ''
    for i in range(4):
        seq += board[i][3-i]
    seqs.append(seq)
    for seq in seqs:
        win = True
        if '.' in seq:
            win = False
        seq = list(set(seq))
        if len(seq) == 2 and 'T' in seq:
            who = seq[0] if seq[1] == 'T' else seq[1]
        elif len(seq) == 1:
            who = seq[0]
        else:
            win = False
        if win:
            winner.add(who)


T = raw_input()
for tcase in range(int(T)):
    board = []
    for i in range(4):
        board.append(raw_input().strip())
    raw_input()  # for empty line
    winner = set()
    check(board, winner)
    if len(winner) is 0:
        if '.' in ''.join(board):
            print 'Case #%d: Game has not completed' % (tcase+1)
        else:
            print 'Case #%d: Draw' % (tcase+1)
    elif len(winner) == 2:
        print 'Case #%d: Draw' % (tcase+1)
    else:
        print 'Case #%d: %s won' % (tcase+1, list(winner)[0])
