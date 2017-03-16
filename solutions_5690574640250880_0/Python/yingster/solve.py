#!/usr/bin/env python
import sys
import numpy as np

def solve(R,C,M):
    board = np.empty((R,C),dtype="S1")
    for r in range(R):
        for c in range(C):
            board[r][c] = "."
    rlim = R
    clim = C

    while(M >= min(rlim,clim)):
        if rlim>=clim:
            for c in range(clim):
                board[rlim-1][c]="*"
            M -= clim
            rlim -= 1
        else:
            for r in range(rlim):
                board[r][clim-1]="*"
            M -= rlim
            clim -= 1
    
    if (M>0):
        board[rlim-1][clim-1] = "*"
        M-=1

    left = clim-2
    up = rlim-2
    while(M>0):
        if left>=up:
            board[rlim-1][left]="*"
            left -= 1
            M-=1
        else:
            board[up][clim-1]="*"
            up -= 1
            M-=1
    testboard = np.array(board)
    flip(testboard,0,0)
    
    testboard = list(testboard.reshape(-1))

    if "." in testboard:
        print "Impossible"
    else:
        board[0][0]='c'
        pboard(board)

def flip(board,r,c):
    if board[r][c]!=".":
        return
    number,arround = get_num(board,r,c)
    board[r][c]=number
    if number==0:
        for (r,c) in arround:
            flip(board,r,c)

def get_num(board,r,c):
    R=len(board)
    C=len(board[0])
    number=0
    arround=[]
    for rtmp in range(r-1,r+2):
        if(rtmp<0 or rtmp>=R):
            continue
        for ctmp in range(c-1,c+2):
            if(ctmp<0 or ctmp>=C):
                continue
            if board[rtmp][ctmp]=="*":
                number+=1
            else:
                arround.append((rtmp,ctmp))
    return number,arround
    

def pboard(board):

    for r in board:
        row=""
        for e in r:
            row+=e
        print row


sys.setrecursionlimit(100000)


numcase = int(sys.stdin.readline())

for casenum in range(1,numcase+1):
    
    config = map(int,sys.stdin.readline().strip().split())

    print 'Case #' + repr(casenum)+':'
    solve(config[0],config[1],config[2])

