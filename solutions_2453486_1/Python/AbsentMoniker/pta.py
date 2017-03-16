#!/usr/bin/python

import sys

#"Constants"
XWON = 0
OWON = 1
DRAW = 2
NOTDONE = 3


def checkRows(game):
    xwin = False
    owin = False
    space = False
    for row in game:
        x = 0
        o = 0
        t = False
        for char in row:
            if char == 'X':
                x+=1
            elif char == 'O':
                o+=1
            elif char == 'T':
                t = True
            elif char == '.':
                space = True
        if x == 4 or (x == 3 and t):
            xwin = True
        elif o == 4 or (o == 3 and t):
            owin = True
    if xwin and owin:
        return (DRAW,space)
    elif xwin:
        return (XWON,space)
    elif owin:
        return (OWON,space)
    else:
        return (NOTDONE,space)

def checkCols(game):
    xwin = False
    owin = False
    for i in range(4):
        x = 0
        o = 0
        t = False
        for j in range(4):
            char = game[j][i]
            if char == 'X':
                x+=1
            elif char == 'O':
                o+=1
            elif char == 'T':
                t = True
        if x == 4 or (x == 3 and t):
            xwin = True
        elif o == 4 or (o == 3 and t):
            owin = True
    if xwin and owin:
        return DRAW
    elif xwin:
        return XWON
    elif owin:
        return OWON
    else:
        return NOTDONE

def checkDiag(game):
    x = 0
    o = 0
    t = False
    xwin = False
    owin = False
    for i in range(4):
        char = game[i][i]
        if char == 'X':
            x+=1
        elif char == 'O':
            o+=1
        elif char == 'T':
            t = True
    if x == 4 or (x == 3 and t):
        xwin = True
    elif o == 4 or (o == 3 and t):
        owin = True
    x = 0
    o = 0
    t = False
    for i in range(4):
        char = game[i][3-i]
        if char == 'X':
            x+=1
        elif char == 'O':
            o+=1
        elif char == 'T':
            t = True
    if x == 4 or (x == 3 and t):
        xwin = True
    elif o == 4 or (o == 3 and t):
        owin = True
    if xwin and owin:
        return DRAW
    elif xwin:
        return XWON
    elif owin:
        return OWON
    else:
        return NOTDONE

if len(sys.argv) != 2:
    print "Usage: ./pta <input file>"
    sys.exit(1)
try:
    fin = open(sys.argv[1])
except IOError:
    print "Error: file could not be opened!"
    sys.exit(1)
data = fin.readlines()
ntests = int(data[0].strip())
line = 1 #Represents current line in file
for i in range(1, ntests+1):
    game = [data[line],data[line+1],data[line+2],data[line+3]]
    line +=5
    result = checkRows(game)
    rowResult = result[0]
    space = result[1]
    colResult = checkCols(game)
    diagResult = checkDiag(game)
    xwins = 0
    owins = 0
    draw = False
    for result in [rowResult,colResult,diagResult]:
        if result == XWON:
            xwins+=1
        elif result == OWON:
            owins+=1
        elif result == DRAW:
            draw = True
    if draw or (xwins>0 and owins>0):
        print "Case #%d: Draw" % i
    elif xwins>0:
        print "Case #%d: X won" % i
    elif owins>0:
        print "Case #%d: O won" % i
    elif space:
        print "Case #%d: Game has not completed" %i
    else:
        print "Case #%d: Draw"%i

sys.exit(0)
