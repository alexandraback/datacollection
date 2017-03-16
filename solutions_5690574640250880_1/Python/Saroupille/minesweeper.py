f=open("test14mw.in", "r")
n_test=int(f.readline())

def gridToStr(grid):
    string=""
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            string+=str(grid[i][j])
        string+="\n"
    return string
  
def compute(H,W,M):
    grid=[["*" for x in range(W)] for y in range(H)]
    if H==1 or W==1:
        for i in range(H*W-M):
            grid[int(i/W)][i%W]="."
        grid[0][0]="c"
        print(gridToStr(grid))
        return gridToStr(grid)
    elif H==2:
        if M%2==1 and M!=H*W-1:
            return "Impossible\n"
        else:
            count=W*H-M
            
            if count==2:
                return "Impossible\n"
            grid[0][0]="c"
            count-=1
            j=0
            while count>0:
                grid[0][j]="."
                grid[1][j]="."
                j+=1
                count-=2

            grid[0][0]="c"
            print(gridToStr(grid))
            return gridToStr(grid)
    elif W==2:
        if M%2==1 and M!=H*W-1:
            return "Impossible\n"
        else:
            count=W*H-M
            
            if count==2:
                return "Impossible\n"
            grid[0][0]="c"
            count-=1
            i=0
            while count>0:
                grid[i][0]="."
                grid[i][1]="."
                i+=1
                count-=2
                
            grid[0][0]="c"
            print(gridToStr(grid))
            return gridToStr(grid)
    else:
        count=H*W-M
        if count==1:
            grid[0][0]="c"
            print(gridToStr(grid))
            return gridToStr(grid)
        elif count<=3 or count==5 or count==7:
            return "Impossible\n"
        elif count==4:
            grid[0][0]="c"
            grid[0][1]="."
            grid[1][0]="."
            grid[1][1]="."
            print(gridToStr(grid))
            return gridToStr(grid)
        elif count==6:
            grid[0][0]="c"
            grid[0][1]="."
            grid[1][0]="."
            grid[1][1]="."
            grid[0][2]="."
            grid[1][2]="."
            print(gridToStr(grid))
            return gridToStr(grid)
        else:
            grid[0][0]="c"
            grid[0][1]="."
            grid[0][2]="."
            grid[1][0]="."
            grid[1][1]="."
            grid[1][2]="."
            grid[2][0]="."
            grid[2][1]="."
            count-=8
            (x,y)=(2,2)
            maxi=False
            maxj=False
            (i,j)=(3,3)
            while not(maxj) and count>0:
                #print(gridToStr(grid))
                if count==1:
                    grid[x][y]="."
                    count-=1
                elif j<W:
                    grid[0][j]="."
                    grid[1][j]="."
                    count-=2
                    j+=1
                else:
                    maxj=True
            #print(count)
            #print(gridToStr(grid))
            while not(maxi) and count>0:
                if count==1:
                    grid[x][y]="."
                    count-=1
                elif i<H:
                    grid[i][0]="."
                    grid[i][1]="."
                    count-=2
                    i+=1
                else:
                    maxi=True
            #print(count)
            #print(gridToStr(grid))
            while count>0:
                #print(gridToStr(grid))
                #print(x,y)
                #print(H,W)
                grid[x][y]="."
                count-=1
                y+=1
                if y>=W:
                    y=2
                    x+=1
        
        print(gridToStr(grid))
        return gridToStr(grid)

for i in range(n_test):
    (H,W,M) = tuple(map(int, f.readline().split(" ")))
    result=compute(H,W,M)
    w=open("result.txt", "a")
    s="Case #"+str(i+1)+":\n"+result
    w=open("result.txt", "a")
    w.write(s)
    w.close()
f.close()
