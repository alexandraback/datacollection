import re

def out(grid):
    row_maxes = [max(x) for x in grid]
    cols = [[grid[i][j] for i in range(len(grid))] for j in range(len(grid[0]))]
    col_maxes = [max(x) for x in cols]
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] != row_maxes[i] and grid[i][j] != col_maxes[j]:
                return "NO"
    return "YES"
        

def get():
    dims = raw_input().split(" ")
    x,y = int(dims[1]), int(dims[0])    
    grid = []
    for i in range(y):
        grid.append([int(x.strip()) for x in raw_input().split(" ")])
    return grid

n = input()
for i in range(n):
        print "Case #"+str(i+1)+": "+out(get())
