import math


def fill_board(x0,y0,xe,ye,m):
    global board
    spaces=(xe-x0)*(ye-y0)
    yy=ye-y0
    xx=xe-x0
    freespaces=spaces-m
    minesplaced=0
    px=0
    py=0
    if 0==0:#freespaces<m:
        if xx>yy and yy<=m:
            #print "chose rr over cc"
            h=y0
            px=px+1
            while h<ye:
                if board[x0][h]==0:
                    board[x0][h]=1
                    minesplaced=minesplaced+1
                h=h+1
        elif xx<=m:
            h=x0
            py=py+1
            while h<xe:
                if board[h][y0]==0:
                    board[h][y0]=1
                    minesplaced=minesplaced+1
                h=h+1
        elif xx-2>=m:
            h=x0
            py=py+1
            px=0
            while h<x0+m:
                if board[h][y0]==0:
                    board[h][y0]=1
                    minesplaced=minesplaced+1
                h=h+1
        elif yy-2>=m:
            h=y0
            px=px+1
            py=0
            while h<y0+m:
                if board[x0][h]==0:
                    board[x0][h]=1
                    minesplaced=minesplaced+1
                h=h+1

        elif xx>yy:
            h=x0
            py=py+1
            while h<xe-2:
                if board[h][y0]==0:
                    board[h][y0]=1
                    minesplaced=minesplaced+1
                h=h+1
        elif yy>=xx:
            h=y0
            px=px+1
            while h<ye-2:
                if board[x0][h]==0:
                    board[x0][h]=1
                    minesplaced=minesplaced+1
                h=h+1
            
        else:
            b=int(math.pow(m,0.5))
            k=x0
            px=px+b
            while k<x0+b:
                j=y0
                while j<y0+b:
                    if board[k][j]==0:
                        board[k][j]=1
                        minesplaced=minesplaced+1
                    j=j+1
                k=k+1
   
    
            
    #show_board()
    results=[]
    results.append(minesplaced)
    results.append(px)
    results.append(py)
    return results

def fill(x,y,m):
    positionx=0
    positiony=0
    global mm
    
    while m>0:
        #print str(positionx)+" "+str(positiony)+" "+str(x)+" "+str(y)+" "+str(m)
        h=fill_board(positionx,positiony,x,y,m)
        positionx=positionx+h[1]
        positiony=positiony+h[2]
        m=m-h[0]
        mm=m
    #show_board()
    global k
    k=0
    for x in board:
        for y in board:
            if y==1:
                k=k+1
   # if k==m:
   #     print "CORRECT"
   # else:
   #     print "ERROR"
        

def show_board():
    for x in board:
        a=''
        for y in x:
            a=a+str(y)
        #print a

            
def check_board():
    global board

    x=0
    while x<len(board):
        y=0
        while y<len(board[0]):

            if x-1>-1:
                if board[x-1][y]==1 and board[x][y]==0:
                    board[x][y]=2
            if x-1>-1 and y-1>-1:
                if board[x-1][y-1]==1 and board[x][y]==0:
                    board[x][y]=2
            if y-1>-1:
                if board[x][y-1]==1 and board[x][y]==0:
                    board[x][y]=2
            if x+1<len(board) and y-1>-1:
                if board[x+1][y-1]==1 and board[x][y]==0:
                    board[x][y]=2
            if x+1<len(board):
                if board[x+1][y]==1 and board[x][y]==0:
                    board[x][y]=2
            if x+1<len(board) and y+1<len(board[0]):
                if board[x+1][y+1]==1 and board[x][y]==0:
                    board[x][y]=2
            if y+1<len(board[0]):
                if board[x][y+1]==1 and board[x][y]==0:
                    board[x][y]=2
            if y+1<len(board[0]) and x-1>-1:
                if board[x-1][y+1]==1 and board[x][y]==0:
                    board[x][y]=2

            y=y+1

        x=x+1

    
    x=0
    while x<len(board):
        y=0
        while y<len(board[0]):

            if x-1>-1:
                if board[x-1][y]==0 and board[x][y]==2:
                    board[x][y]=3
            if x-1>-1 and y-1>-1:
                if board[x-1][y-1]==0 and board[x][y]==2:
                    board[x][y]=3
            if y-1>-1:
                if board[x][y-1]==0 and board[x][y]==2:
                    board[x][y]=3
            if x+1<len(board) and y-1>-1:
                if board[x+1][y-1]==0 and board[x][y]==2:
                    board[x][y]=3
            if x+1<len(board):
                if board[x+1][y]==0 and board[x][y]==2:
                    board[x][y]=3
            if x+1<len(board) and y+1<len(board[0]):
                if board[x+1][y+1]==0 and board[x][y]==2:
                    board[x][y]=3
            if y+1<len(board[0]):
                if board[x][y+1]==0 and board[x][y]==2:
                    board[x][y]=3
            if y+1<len(board[0]) and x-1>-1:
                if board[x-1][y+1]==0 and board[x][y]==2:
                    board[x][y]=3

            y=y+1

        x=x+1
    
    show_board()
    #check_board()
    

def generate_board():
    foundc=False
    b=''
    r=0
    while r<len(board):
        c=0
        a=''
        while c<len(board[0]):
            y=board[r][c]
            if y==1:
                a=a+'*'
            elif y==0 or y==2:
                if not foundc:
                    a=a+'c'
                    foundc=True
                else:
                    a=a+'.'
            elif y==3:
                a=a+'.'
            c=c+1
        if r<len(board)-1:
            a=a+'\r\n'
        r=r+1
   
        b=b+a
    
    return b
    

def newfill(x,y,m,casen):
    global board
    board=[[0 for i in range(0,y)] for i in range(0,x)]
    fill(x,y,m)
    check_board()

    num2=0
    num3=0
    num1=0
    num0=0
    for x in board:
        for y in x:
            if y==2:
                num2=num2+1
            elif y==3:
                num3=num3+1
            elif y==0:
                num0=num0+1
            elif y==1:
                num1=num1+1
                

    possible=False
    if num0==0 and num2==1 and num3==0:
        possible=True
    elif num2>0:
        possible=False
    elif num0==0 and num2==0:
        possible=False
    elif num0==0 and num2==0 and num3==0:
        possible=False
    elif num2==0:
        possible=True

    if possible:
        p=generate_board()
        answer='Case #'+str(casen+1)+":"
        newfile.write(answer)
        newfile.write('\r\n')
        newfile.write(p)
        newfile.write('\r\n')
    else:
        answer='Case #'+str(casen+1)+":"
        newfile.write(answer)
        newfile.write('\r\n')
        newfile.write('Impossible')
        newfile.write('\r\n')
        
        
    
    




#n=int(raw_input())
#a=[int(x) for x in raw_input().split()] 

#filename='C-small.in'
filename='C-large.in'
ff=open(filename)
newfile=open('output.txt','wb')
board=[]
t=int(ff.readline())
a=0




while a<t:

    nums=ff.readline().split()
    r=int(nums[0])
    c=int(nums[1])
    m=int(nums[2])

    board=[[0 for i in range(0,c)] for i in range(0,r)]
    
    #fill(c,r,m)
    newfill(r,c,m,a)


    print a
    a=a+1


newfile.close()
