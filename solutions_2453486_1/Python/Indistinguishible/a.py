lines = open('a.in').read().split("\n")
f = open('a.out', 'w')

n = int(lines[0])
for i in range(1, n+1):
    s = 1+(i-1)*5
    if '.' in lines[s] or '.' in lines[s+1] or '.' in lines[s+2] or '.' in lines[s+3]:
        res = "Game has not completed"
    else:
        res = "Draw"
    board = lines[s:5*i]
    outs = board + [board[0][0]+board[1][0]+board[2][0]+board[3][0], board[0][1]+board[1][1]+board[2][1]+board[3][1], board[0][2]+board[1][2]+board[2][2]+board[3][2], board[0][3]+board[1][3]+board[2][3]+board[3][3], board[0][0]+board[1][1]+board[2][2]+board[3][3], board[3][0]+board[2][1]+board[1][2]+board[0][3]]
    for l in outs:
        if 'T' in l:
            if l.replace('T', 'X') == 'XXXX':
                res = 'X won'
                break
            elif l.replace('T', 'O') == 'OOOO':
                res = 'O won'
                break
        if l == 'XXXX':
            res = 'X won'
            break
        elif l == 'OOOO':
            res = 'O won'
            break
    f.write("Case #%d: %s\n" % (i, res))

f.close()
