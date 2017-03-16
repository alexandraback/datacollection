import math
X=open("blg.in")
z=open("output.txt","w")        

def column(board,col):
    curCol=[]
    for row in range(0,len(board)):
        curCol.append(board[row][col])
    return curCol

def processGrass(board):
    for row in range(0,len(board)):
        for col in range(0,len(board[0])):
            if not board[row][col]==max(board[row]) and not board[row][col]==max(column(board,col)):
                return "NO"
    return "YES"
    

case=0
cases=int(X.readline())
while case<cases:
    case+=1
    currentline=X.readline().rstrip().lstrip().split()
    rows=int(currentline[0])
    board=[]
    while rows:
        rows-=1
        board.append(X.readline().rstrip().lstrip().split())
    print case
    for row in range(0,len(board)):
        for col in range(0,len(board[0])):
            board[row][col]=int(board[row][col])
    z.write("Case #"+str(case)+": "+processGrass(board)+"\n")
z.close()
