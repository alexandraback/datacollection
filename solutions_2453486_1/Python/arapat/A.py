
import sys

def output(msg, loop):
    print 'Case #' + str(loop) + ': ' + msg


X = 'X won'
O = 'O won'
tie = 'Draw'
tbc = 'Game has not completed'


def horizon(k, data, msg):
    r = data[k][0]
    if r == 'T':
        r = data[k][1]
    if r != '.':
        end = True
        for itr in range(4):
            if data[k][itr] != r and data[k][itr] != 'T':
                end = False
        if end:
            return eval(r)
    return msg


def vertical(k, data, msg):
    r = data[0][k]
    if r == 'T':
        r = data[1][k]
    if r != '.':
        end = True
        for itr in range(4):
            if data[itr][k] != r and data[itr][k] != 'T':
                end = False
        if end:
            return eval(r)
    return msg


def diag(rg, data, msg):
    r = data[0][rg[0]]
    if r == 'T':
        r = data[1][rg[1]]
    if r != '.':
        end = True
        for itr in range(4):
            if data[itr][rg[itr]] != r and data[itr][rg[itr]] != 'T':
                end = False
        if end:
            return eval(r)
    return msg


def full(data):
    for item in data:
        if item.find('.') >= 0:
            return tbc
    return None


T = int(sys.stdin.readline().strip())
for loop in range(1, T+1):
    data = []
    for i in range(4):
        data.append(sys.stdin.readline().strip())
    sys.stdin.readline()
    
    msg = full(data)
    for i in range(4):
        msg = horizon(i, data, msg)
        msg = vertical(i, data, msg)
    msg = diag(range(4), data, msg)
    msg = diag(range(3,-1,-1), data, msg)
    if msg == None:
        msg = tie
    output(msg, loop)

