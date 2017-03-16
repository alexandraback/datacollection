#!/usr/bin/python3
import sys

f = open("A-large.in")
g = open("A-large.out", "w")

T = int(f.readline())

def won(field, player):
    row = any(all(field[r][c] in player+'T' for c in range(4)) for r in range(4))
    col = any(all(field[r][c] in player+'T' for r in range(4)) for c in range(4))
    diag = all(field[r][r] in player+'T' for r in range(4)) or all(field[r][3-r] in player+'T' for r in range(4))
    return row or col or diag

def draw(field):
    return '.' not in ''.join(field)
    
for caseNo in range(1, T+1):
    field = [f.readline().strip() for r in range(4)]
    f.readline() # gobble additinal empty line
    if won(field, 'X'):
        print("Case #{0}: X won".format(caseNo), file=g)
    elif won(field, 'O'):
        print("Case #{0}: O won".format(caseNo), file=g)
    elif draw(field):
        print("Case #{0}: Draw".format(caseNo), file=g)
    else:
        print("Case #{0}: Game has not completed".format(caseNo), file=g)
    # print(field)

g.close()
