_xWon = ['XXXX'] + ['X' * i + 'T' + 'X' * (3 - i) for i in range(4)]
_oWon = ['OOOO'] + ['O' * i + 'T' + 'O' * (3 - i) for i in range(4)]
def checkState(board):
    allRows = board + [''.join(board[x][y] for x in range(4)) for y in range(4)]
    allRows.append(''.join(board[x][x] for x in range(4)))
    allRows.append(''.join(board[x][3 - x] for x in range(4)))
    for i in _xWon:
        if i in allRows:
            return 'X won'
    for i in _oWon:
        if i in allRows:
            return 'O won'
    for i in board:
        if '.' in i:
            return 'Game has not completed'
    return 'Draw'



fin = open('A-large.in', 'r') 
T = int(fin.readline().split()[0])
caseNo = 0
fout = open('A-large.out', 'w')
for i in range(T):
    board = [fin.readline().rstrip() for j in range(4)]
    fin.readline()
    caseNo += 1
    fout.write('Case #' + str(caseNo) + ': ' + checkState(board) + '\n')

fin.close()
fout.close()

