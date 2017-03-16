
# -*- coding: cp932 -*-

import sys



def checkSum( s ):
    if s & 0xF0 == 0x40:
        return 0x10
    elif s & 0x0F == 0x04:
        return 0x01
    else:
        return 0x00
    
def checkBoard( board ):
    for i in range(4):
        # row
        s = 0
        for j in range(4):
            s += board[i][j]
            result = checkSum(s)
            if result != 0x00: return result
        # column
        s = 0
        for j in range(4):
            s += board[j][i]
            result = checkSum(s)
            if result != 0x00: return result
    # diagonal
    s = 0
    for i in range(4):
        s += board[i][i]
    result = checkSum(s)
    if result != 0x00: return result
    s = 0
    for i in range(4):
        s += board[i][3-i]
    result = checkSum(s)

    return result



inputfile = "A-large.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')

tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    board = [[0 for j in range(4)] for i in range(4)]
# . , T , O , X
    hasDot = False
    for i in range(4):
        line = f.readline().rstrip()
        for j in range(4):
            if line[j] == "T":
                board[i][j] = 0x11
            elif line[j] == "O":
                board[i][j] = 0x01
            elif line[j] == "X":
                board[i][j] = 0x10
            else:
                hasDot = True
                
    f.readline()
    result = checkBoard(board)
    
    resultStr = ""
    if result == 0x01:
        resultStr = "O won"
    elif result == 0x10:
        resultStr = "X won"
    elif hasDot:
        resultStr = "Game has not completed"
    else:
        resultStr = "Draw"
        
    print("Case #" + str(tc+1) + ": " + resultStr)

