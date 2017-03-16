t=input()
import copy
def make_zero(grid,x,y,dots):
    if x<len(grid[0]) and x>=0:
        if y<len(grid) and y>=0:
            if x>0 and grid[y][x-1]!='.':
                grid[y][x-1]='.'
                dots-=1
            if y>0 and grid[y-1][x]!='.':
                grid[y-1][x]='.'
                dots-=1
            if x>0 and y>0 and  grid[y-1][x-1]!='.':
                grid[y-1][x-1]='.'
                dots-=1
            if x<len(grid[0])-1 and grid[y][x+1]!='.':
                grid[y][x+1]='.'
                dots-=1
            if y<len(grid)-1 and grid[y+1][x]!='.':
                grid[y+1][x]='.'
                dots-=1
            if x<len(grid[0])-1 and y<len(grid)-1 and grid[y+1][x+1]!='.':
                grid[y+1][x+1]='.'
                dots-=1
            if x<len(grid[0])-1 and y>0 and grid[y-1][x+1]!='.':
                grid[y-1][x+1]='.'
                dots-=1
            if x>0 and y<len(grid)-1 and grid[y+1][x-1]!='.':
                grid[y+1][x-1]='.'
                dots-=1
    return grid,dots

def check(grid,grid2,x,y,dots,x1,y1):
#     print dots,' dots',x,':x ',y,':y '
#     for i in range(len(grid)):
#         print grid[i]
#     for i in range(len(grid)):
#         print grid2[i]
    if x>=0 and y>=0 and x<len(grid[0]) and y<len(grid) and grid[y][x]!='.':
        grid[y][x]='.'
        dots-=1
    if dots==0:
        #print 'sol:'
        grid[y1][x1]='c'
        for i in range(len(grid)):
            s=''
            for j in range(len(grid[0])):
                s+=grid[i][j]
            print s
        #exit()
        return 1
    if dots<0:
        return 0
    
    if x>=0 and y>=0 and x<len(grid[0]) and y<len(grid):
        grid2[y][x]=0
    else:
        return 0
    grid,dots=make_zero(grid,x,y,dots)
#     print 'after make zero',dots
#     for i in range(len(grid)):
#         print grid[i]
#     for i in range(len(grid)):
#         print grid2[i]
    if dots<0:
        #print 'done'
        return 0
    if dots==0:
        #print 'sol:'
        grid[y1][x1]='c'
        for i in range(len(grid)):
            s=''
            for j in range(len(grid[0])):
                s+=grid[i][j]
            print s 
#        exit()
        return 1
    if x>0 and grid2[y][x-1]!=0:
        if check(copy.deepcopy(grid),copy.deepcopy(grid2),x-1,y,dots,x1,y1):
            return 1
    if y>0 and grid2[y-1][x]!=0:
        if check(copy.deepcopy(grid),copy.deepcopy(grid2),x,y-1,dots,x1,y1):
            return 1
    if x>0 and y>0 and  grid2[y-1][x-1]!=0:
        if check(copy.deepcopy(grid),copy.deepcopy(grid2),x-1,y-1,dots,x1,y1):
            return 1
    if x<len(grid[0])-1 and grid2[y][x+1]!=0:
        if check(copy.deepcopy(grid),copy.deepcopy(grid2),x+1,y,dots,x1,y1):
            return 1
    if y<len(grid)-1 and grid2[y+1][x]!=0:
        if check(copy.deepcopy(grid),copy.deepcopy(grid2),x,y+1,dots,x1,y1):
            return 1
    if x<len(grid[0])-1 and y<len(grid)-1 and grid2[y+1][x+1]!=0:
        if check(copy.deepcopy(grid),copy.deepcopy(grid2),x+1,y+1,dots,x1,y1):
            return 1
    if x<len(grid[0])-1 and y>0 and grid2[y-1][x+1]!=0:
        if check(copy.deepcopy(grid),copy.deepcopy(grid2),x+1,y-1,dots,x1,y1):
            return 1
    if x>0 and y<len(grid)-1 and grid2[y+1][x-1]!=0:
        if check(copy.deepcopy(grid),copy.deepcopy(grid2),x-1,y+1,dots,x1,y1):
            return 1
    return 0
    
    
for case in range(0,t):
    line=raw_input().split()
    r=int(line[0])
    c=int(line[1])
    m=int(line[2])
    grid=[]
    count=0
    for i in range(0,r):
        row=[]
        for j in range(0,c):
#            if count<m:
#                 row.append('*')
#                 count+=1
#             else:
                row.append('*')
        grid.append(row)
    #print grid
    grid2=[]
    count=0
    for i in range(0,r):
        row=[]
        row.append(5)
        for j in range(0,c-1):
            if j<c-2:
                row.append(8)
            else:
                row.append(5)
        grid2.append(row)
    for j in range(0,c):
        grid2[0][j]=5
    if c>1:
        grid2[0][0]=3
        grid2[0][c-1]=3
        grid2[r-1][0]=3
        grid2[r-1][c-1]=3
    else:
        grid2[0][0]=1
        grid2[r-1][0]=1
    if r>1:
        grid2[r-1][0]=3
    else:
        if c==1:
            grid2[0][0]=0
        else:
            grid2[0][0]=1
            grid2[0][c-1]=1
    #print grid2
        
    xi=c/2
    yi=r/2
    dots=r*c-m
    flag=0
    print "Case #%d:"%(case+1)
    if not check(copy.deepcopy(grid),copy.deepcopy(grid2),xi,yi,dots,xi,yi):
        for i in range(r):
            for j in range(c):
                #print 'new'
#                 for i in range(len(grid)):
#                     print grid[i]
                if check(copy.deepcopy(grid),copy.deepcopy(grid2),j,i,dots,i,j):
                    flag=1
                    break
            if flag:
                break
        if not flag:
            print "Impossible"
#     if dots==0:
#         for i in range(len(grid)):
#             print grid[i]
#     else:
            