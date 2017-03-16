#!/usr/bin/python

def read_board() :
    b = [ raw_input() for i in xrange(4) ]
    raw_input()
    return b

def check_win(b, ch) :
    nb = [ i.replace('T', ch) for i in b ]
    if ch * 4 in nb :
        return True
    for i in xrange(4) :
        flag = True
        for j in xrange(4) :
            if nb[j][i] != ch :
                flag = False
                break
        if flag :
            return True
    if nb[0][0] == ch and nb[1][1] == ch and nb[2][2] == ch and nb[3][3] == ch :
        return True
    if nb[0][3] == ch and nb[1][2] == ch and nb[2][1] == ch and nb[3][0] == ch :
        return True
    return False


T = int(raw_input())
for t in xrange(1, T + 1) :
    b = read_board()
    x_win = check_win(b, 'X')
    o_win = check_win(b, 'O')
    if x_win :
        r = 'X won'
    elif o_win :
        r = 'O won'
    else :
        if '.' in ''.join(b) :
            r = 'Game has not completed'
        else :
            r = 'Draw'
    print 'Case #%d: %s' % (t, r)


