import math


def processBoard(curBoard):
    for row in curBoard:
        if row.count(".")==0 and (len(set(row))==1 or (len(set(row))==2 and row.count("T")>0)):
            if not row[0]=="T":
                return row[0]+" won"
            else:
                return row[1]+" won"
    for col in range(0,4):
        current=curBoard[0][col]+curBoard[1][col]+curBoard[2][col]+curBoard[3][col]
        if current.count(".")==0 and (len(set(current))==1 or (len(set(current))==2 and current.count("T")>0)):
            if not current[0]=="T":
                
                return current[0]+" won"
            else:
                return current[1]+" won"
    current=curBoard[0][0]+curBoard[1][1]+curBoard[2][2]+curBoard[3][3]
    if current.count(".")==0 and (len(set(current))==1 or (len(set(current))==2 and current.count("T")>0)):
        if not current[0]=="T":
                
            return current[0]+" won"
        else:
            return current[1]+" won"
    current=curBoard[0][3]+curBoard[1][2]+curBoard[2][1]+curBoard[3][0]
    if current.count(".")==0 and (len(set(current))==1 or (len(set(current))==2 and current.count("T")>0)):
        
        if not current[0]=="T":
                
            return current[0]+" won"
        else:
            return current[1]+" won"
    
    for row in range(0,4):
        for col in range(0,4):
            if curBoard[row][col]==".":
                return "Game has not completed"
    return "Draw"

X=open("asm2.in")
z=open("output.txt","w")
case=0
cases=int(X.readline())

while case<cases:
    case+=1
    print case
    board=[]
    for x in range(0,4):
        currentline=X.readline().rstrip().lstrip()
        board.append(currentline)
    print board
    currentline=X.readline()
    z.write("Case #"+str(case)+": "+processBoard(board)+"\n")
z.close()
