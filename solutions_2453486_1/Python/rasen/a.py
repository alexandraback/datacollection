#!/usr/bin/env python3
from sys import stdin

n = int(stdin.readline())

def column(b, col):
    ret = ''
    for i in b:
        ret += i[col]
    return ret

def check_array(b):
    # Check rows
    for i in range(4):
        if b[i].count('X') + b[i].count('T') == 4:
            return 'X won'
        if b[i].count('O') + b[i].count('T') == 4:
            return 'O won'
    # Check cols
    for i in range(4):
        if column(b,i).count('X') + column(b,i).count('T') == 4:
            return 'X won'
        if column(b,i).count('O') + column(b,i).count('T') == 4:
            return 'O won'
    # Check diags
    x1 = o1 = x2 = o2 = t1 = t2 = 0
    for i in range(4):
        x1 += int(b[i][i]   == 'X')
        x2 += int(b[i][3-i] == 'X')
        o1 += int(b[i][i]   == 'O')
        o2 += int(b[i][3-i] == 'O')
        t1 += int(b[i][i]   == 'T')
        t2 += int(b[i][3-i] == 'T')
    if x1 + t1 == 4 or x2 + t2 == 4:
        return 'X won'
    if o1 + t1 == 4 or o2 + t2 == 4:
        return 'O won'
    # Count dots
    dots = 0
    for i in b:
        dots += i.count('.')
    if dots != 0:
        return 'Game has not completed'
    else:
        return 'Draw'

for k in range(1, n+1):
    # Read array
    b = []
    for i in range(4):
        b.append(stdin.readline())
    stdin.readline()

    print('Case #', k, ': ', check_array(b), sep='')

