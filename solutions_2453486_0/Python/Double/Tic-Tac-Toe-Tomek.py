#!/usr/bin/env python
T=int(raw_input().strip())

board=['']*4

def line_status(line):
    if line.count('X')==4 or line.count('X')==3 and line.count('T')==1:
        return 1
    if line.count('O')==4 or line.count('O')==3 and line.count('T')==1:
        return 2
    return 0
def get_status():
    lines=[]
    for i in range(4):
        lines.append(board[i])
        line=board[0][i]+board[1][i]+board[2][i]+board[3][i]
        lines.append(line)
    lines.append(board[0][0]+board[1][1]+board[2][2]+board[3][3])
    lines.append(board[0][3]+board[1][2]+board[2][1]+board[3][0])
    for line in lines:
        s=line_status(line)
        if s==1:
            return 'X won'
        elif s==2:
            return 'O won'
    if '.' in ''.join(lines):
        return 'Game has not completed'
    return 'Draw'

for i in range(1, T+1):
    for j in range(4):
        board[j]=raw_input().strip()
    print 'Case #%d: %s' % (i, get_status())
    if i!=T:
        raw_input()

