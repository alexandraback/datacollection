#!/usr/bin/env python3

def check_winner(board, player):
    pboard = [line.replace('T', player) for line in board]
    for i in range(4):
        if (player * 4) in pboard[i]:
            return True
        flag = True
        for j in range(4):
            if pboard[j][i] != player:
                flag = False
        if flag:
            return True

    flag = True
    for i in range(4):
        if pboard[i][i] != player:
            flag = False
    if flag:
        return True

    flag = True
    for i in range(4):
        if pboard[4 - i - 1][i] != player:
            flag = False
    if flag:
        return True

    return False

def solve(fin, fout):
    board = [fin.readline() for i in range(4)]
    fin.readline() # Empty line
    if check_winner(board, 'X'):
        fout.write('X won\n')
    elif check_winner(board, 'O'):
        fout.write('O won\n')
    elif len([1 for line in board if '.' in line]) > 0:
        fout.write('Game has not completed\n')
    else:
        fout.write('Draw\n')

