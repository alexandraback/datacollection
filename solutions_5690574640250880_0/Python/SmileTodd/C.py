import sys
import copy

def display(grid,R,C,M):
    s = "\n"
    if grid==[] :
        s+="Impossible"
    else:
        for i in range(R):
            for j in range(C):
                s+=grid[i][j]
            if i < R-1 :
                s+="\n"
    return s

def border(grid):
    border = []
    len_i = len(grid)
    len_j = len(grid[0])
    for i in range(len_i):
        for j in range(len_j):
            if(grid[i][j]!="*"):
                if(i>0):
                    if(grid[i-1][j]=="*"):
                        border.append([i,j])
                        continue
                if(i<len_i-1):
                    if(grid[i+1][j]=="*"):
                        border.append([i,j])
                        continue
                if(j>0):
                    if(grid[i][j-1]=="*"):
                        border.append([i,j])
                        continue
                if(j<len_j-1):
                    if(grid[i][j+1]=="*"):
                        border.append([i,j])
                        continue
    return border


def click(grid,i,j):
    grid[i][j]="."
    len_i = len(grid)
    len_j = len(grid[0])
    if(i>0):
        grid[i-1][j]="."
        if(j>0):
            grid[i-1][j-1]="."
        if(j<len_j-1):
            grid[i-1][j+1]="."
    if(j>0):
        grid[i][j-1]="."
    if(j<len_j-1):
        grid[i][j+1]="."
    if(i<len_i-1):
        grid[i+1][j]="."
        if(j>0):
            grid[i+1][j-1]="."
        if(j<len_j-1):
            grid[i+1][j+1]="."
    return grid


def num(grid):
    n = 0
    for i in grid:
        for j in i:
            if(j=="*"):
                n+=1
    return n

def judge(grid,M,result):
    for coord in border(grid):
        g=copy.deepcopy(grid)
        g = click(g,coord[0],coord[1])
        if(num(g)<M):
            continue
        elif(num(g)==M):
            result.append(g)
            break
        else:
            judge(g,M,result)


def putC(grid,R,C,M):
    result=[]
    for i in range(R):
        for j in range(C):
            g=copy.deepcopy(grid)
            g= click(g,i,j)
            if num(g)==M :
                g[i][j]="c"
                return g
            judge(g,M,result)
            if result!=[] :
                result [0][i][j]="c"
                return result[0]
    return []

def solve(R,C,M):
    grid = []
    for i in range(R):
        a=[]
        for j in range(C):
            a.append("*")
        grid.append(a)
    if(R*C-M!=1):
        grid = putC(grid,R,C,M)
    else:
        grid[0][0]="c"
    return display(grid,R,C,M)

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
    R,C,M = [int(i) for i in sys.stdin.readline().strip().split()]
    print 'Case #'+repr(casenum)+":"+solve(R,C,M)
