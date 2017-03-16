#!/usr/bin/python

import fileinput

XWIN = 'X'
OWIN = 'O'
CATZ = 'C' 
INC = '.'

def checkl(l):
    c = l[0]
    for e in l:
        if(e == '.'):
            return '.' 
        if(e == 'T'):
            continue
        if(c == 'T'):
            c = e
        if(c != e):
            c = 'C'
    return c  

case = 1
board = []
for linenum, line in enumerate(fileinput.input()):
    line = line.strip()
    if linenum == 0:
        cases = int(line)
        continue
    if linenum % 5 in [1,2,3]:
        board.append(line)
        continue
    elif linenum % 5 == 0:
        board = []
        case +=1
        continue
        
    board.append(line)

    checks = ""
    for n in xrange(4):
        checks += checkl([li[n] for li in board])
        checks += checkl([c for c in board[n]])
    checks += checkl([board[0][0], board[1][1], board[2][2], board[3][3]])
    checks += checkl([board[0][3], board[1][2], board[2][1], board[3][0]])

    result = ""
    if 'X' in checks:
        result = "X won"
    elif 'O' in checks:
        result = "O won"
    elif '.' in checks:
        result = "Game has not completed" 
    else:
        result = "Draw"

    print "Case #{0}: {1}".format(case, result)

    if case == cases:
        break
