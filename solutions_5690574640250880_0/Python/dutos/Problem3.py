import os, re, math
 
inf = open('problem3.txt', 'r')
 
numproblems = int(inf.readline())
 
outf = open('out3.txt', 'w')

x = 0
y = 0
mines = 0
empties = 0
board = []

def PlaceEmpty(board, cx, cy):
    global x
    global y

    if x > y:
        blahx = 1.0
        blahy = float(x) / float(y)
    elif y > x:
        blahx = float(y) / float(x)
        blahy = 1.0
    else:
        blahx = 1.0
        blahy = 1.0
    
    minx = 0
    miny = 0
    mindist = 10000000000.0
    for i in range(y):
        for j in range(x):
            if board[i][j] == '*':
                dx = float(j - cx)
                dy = float(i - cy)
                dist = dx * dx * blahx  + dy * dy * blahy
                if dist < mindist:
                    minx = j
                    miny = i
                    mindist = dist
    board[miny][minx] = '.'

def IsMine(board, mx, my):
    global x
    global y

    if mx < 0 or mx > x - 1:
        return 0
    if my < 0 or my > y - 1:
        return 0
    if board[my][mx] == '*':
        return 1
    return 0

def CountMines(board, numboard):
    global x
    global y
    for j in range(y):
        for i in range(x):
            mines = 0
            mines += IsMine(board, i - 1, j)
            mines += IsMine(board, i - 1, j - 1)
            mines += IsMine(board, i - 1, j + 1)
            mines += IsMine(board, i + 1, j)
            mines += IsMine(board, i + 1, j - 1)
            mines += IsMine(board, i + 1, j + 1)
            mines += IsMine(board, i, j)
            mines += IsMine(board, i, j - 1)
            mines += IsMine(board, i, j + 1)
            numboard[j][i] = mines
    
def Reveal(revealboard, numboard, rx, ry):
    if rx >= 0 and rx < x and ry >= 0 and ry < y:
        revealboard[ry][rx] = True
        if numboard[ry][rx] == 0:
            return True
    return False

def Checked(checkboard, rx, ry):
    if rx >= 0 and rx < x and ry >= 0 and ry < y:
        return checkboard[ry][rx]
    return True

def OneClickWin(board, tx, ty):
    global x
    global y

    revealboard = [[False]*x for i in range(y)]
    checkboard = [[False]*x for i in range(y)]
    numboard = [[0]*x for i in range(y)]

    CountMines(board, numboard)

    #PrintBoard(board)
    #PrintNumboard(numboard)
    
    reveallist = [(tx, ty)]
    while reveallist:
        (rx, ry) = reveallist[0]
        reveallist.remove((rx, ry))
        if checkboard[ry][rx] == False:
            checkboard[ry][rx] = True
            
            mine = Reveal(revealboard, numboard, rx, ry)
            if mine:
                for i in [-1, 0, 1]:
                    for j in [-1, 0, 1]:
                        if i == 0 and j == 0:
                            continue
                        px = rx + i
                        py = ry + j
                        if Checked(checkboard, px, py) == False and Reveal(revealboard, numboard, px, py):
                            reveallist.append((px, py))

    #PrintBoard(board)
    #PrintNumboard(numboard)
    #PrintRevealboard(checkboard)
    #PrintRevealboard(revealboard)
                    
    for i in range(x):
        for j in range(y):
            if board[j][i] == '.' and revealboard[j][i] == False:
                return False
    return True

def TryBoard(tx, ty):
    global x
    global y
    global empties

    e = empties
    board = [['*']*x for i in range(y)]
    board[ty][tx] = 'c'

    while e:
        PlaceEmpty(board, tx, ty)
        e -= 1

    val = OneClickWin(board, tx, ty)
    return (board, val)

def PrintBoard(board):
    global x
    global y

    msg = ''
    for i in range(y):
        for j in range(x):
            msg = msg + board[i][j]
        msg = msg + '\n'
    print msg
    
def PrintNumboard(board):
    global x
    global y

    msg = ''
    for i in range(y):
        for j in range(x):
            msg = msg + str(board[i][j])
        msg = msg + '\n'
    print msg

def PrintRevealboard(board):
    global x
    global y

    msg = ''
    for i in range(y):
        for j in range(x):
            blah = 'f'
            if board[i][j] == True:
                blah = 't'
            msg = msg + blah
        msg = msg + '\n'
    print msg

impossible = 0
for problemnum in range(numproblems):
    values = inf.readline()
    values = re.sub('\n', '', values)
    values = values.split()
 
    y = int(values[0])
    x = int(values[1])
    mines = int(values[2])
    empties = x * y - mines - 1 # 1 for the click

    for i in range(x):
        for j in range(y):
            (board, win) = TryBoard(i, j)
            if win == True:
                break
        if win == True:
            break
            
    if win == True:
        #continue
        msg = 'Case #' + str(problemnum + 1) + ':'
        for i in range(y):
            msg = msg + '\n'
            for j in range(x):
                msg = msg + board[i][j]
           
    else:
        impossible += 1
        msg = 'Case #' + str(problemnum + 1) + ':\nImpossible'
        #print '%d %d %d' % (x, y, mines)

    print msg
    outf.write(msg + '\n')

print impossible
outf.close()
inf.close()
