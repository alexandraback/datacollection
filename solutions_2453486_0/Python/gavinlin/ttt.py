# Codejam Q Round

def check(s):

    # Take in a string of char, check if there's a winner
    # If so, return the winner, otherwise return 'N'

    x = 0
    o = 0
    for c in s:
        if c == 'X':
            x+=1
        if c == 'O':
            o+=1
        if c == 'T':
            x+=1
            o+=1

    # return winner
    if x == 4:
        return 'X'
    if o == 4:
        return 'O'

    return 'N'

def func():
    x = False
    o = False
    dot = False

    board = []
    # horizontal
    for i in xrange(0,4):
        line = raw_input()
        board += [line]
        dot = dot or ("." in line)
        res = check(line)
        if res == 'X':
            x = True
        elif res == 'O':
            o = True

    # vertical
    for i in xrange(0,4):
        line = board[0][i]+board[1][i]+board[2][i]+board[3][i]
        res = check(line)
        if res == 'X':
            x = True
        elif res == 'O':
            o = True

    #diagonal
    line = board[0][0]+board[1][1]+board[2][2]+board[3][3]
    res = check(line)
    if res == 'X':
        x = True
    elif res == 'O':
        o = True

    line = board[0][3]+board[1][2]+board[2][1]+board[3][0]
    res = check(line)
    if res == 'X':
        x = True
    elif res == 'O':
        o = True
         
    if x:
        return 'X won'
    elif o:
        return 'O won'
    elif dot:
        return 'Game has not completed'
    else:
        return 'Draw'

# Main
t = int(raw_input())

for i in xrange(0,t):
    print "Case #%d:" % (i+1), func()
    empty = raw_input()
