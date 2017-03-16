import sys
sys.stdin = open("A-small-attempt1.in")
sys.stdout = open("OAout.txt","w")

N = int(input())
board = []

def test(board):
    count=0
    dot=True
    #columns
    for r in range(4):
        for c in range(4):
            if board[r][c]=='X':
                count+=1
            if board[r][c]=='O':
                count-=1
            if board[r][c]=='.':
                count=999;
                dot=False
        if count==3 or count==4:
            return 'X won'
        if count==-3 or count==-4:
            return 'O won'
        count=0
    #rows
    for c in range(4):
        for r in range(4):
            if board[r][c]=='X':
                count+=1
            if board[r][c]=='O':
                count-=1
            if board[r][c]=='.':
                count=999;
                dot=False
        if count==3 or count==4:
            return 'X won'
        if count==-3 or count==-4:
            return 'O won'
        count=0
    #diagonal
    for rc in range(4):
        if board[rc][rc]=='X':
            count+=1
        if board[rc][rc]=='O':
            count-=1
        if board[rc][rc]=='.':
            count=999;
            dot=False
        if count==3 or count==4:
            return 'X won'
        if count==-3 or count==-4:
            return 'O won'
        count=0
    for rc in range(4):
        if board[rc][rc]=='X':
            count+=1
        if board[rc][rc]=='O':
            count-=1
        if board[rc][rc]=='.':
            count=999;
            dot=False
    if count==3 or count==4:
        return 'X won'
    if count==-3 or count==-4:
        return 'O won'
    count=0

    for rc in range(4):
        if board[rc][3-rc]=='X':
            count+=1
        if board[rc][3-rc]=='O':
            count-=1
        if board[rc][3-rc]=='.':
            count=999;
            dot=False
    if count==3 or count==4:
        return 'X won'
    if count==-3 or count==-4:
        return 'O won'
    count=0
    if dot:
        return "Draw"
    return "Game has not completed"
    

for _ in range(N):
    for i in range(4):
        board.append(input());
    if _!=N-1:
        input()
    print("Case #"+str(_+1)+": "+test(board))
    board=[]
sys.stdout.close()
