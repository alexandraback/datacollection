#!/usr/bin/env python3
# Bill Cooperman (aquamongoose)
# Google Code Jam Qualification Round
# Problem A
T = int(input())
N = 4
board = ['.'*N]*N

def going():
    global board, N
    for line in board:
        if line.find('.') != -1:
            return True
    return False

def win(p):
    global board, N
    for i in range(N):
        g1 = g2 = True
        for j in range(N):
            if board[i][j] not in {p, 'T'}:
                g1 = False
            if board[j][i] not in {p, 'T'}:
                g2 = False
        if g1 or g2:
            return True
    g1 = g2 = True
    for i in range(N):
        if board[i][i] not in {p, 'T'}:
            g1 = False
        if board[i][N-i-1] not in {p, 'T'}:
            g2 = False
    return g1 or g2

for i in range(T):
    print("Case #{}:".format(i+1),end=' ')
    for j in range(N):
        board[j] = input()
    input()
    if win('X') and not win('O'):
        print("X won")
    elif win('O') and not win('X'):
        print("O won")
    elif going():
        print("Game has not completed")
    else:
        print("Draw")
