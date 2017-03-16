from IOManager import formatInput, readInput, writeOutput

def solve(data):
    cases = formatInput(data,[1],[str])
    results = []
    
    for case in cases:
        
        rows = int(case[0].split(" ")[0])
        cols = int(case[0].split(" ")[1])
        mines = int(case[0].split(" ")[2])
        
        n = rows*cols
        
        s = "\n"
        
        if rows > 1 and cols > 1:
            free = n-mines
            
            b = [["*" for _ in range(cols)] for _ in range(rows)]
            
            if free == 1:
                
                b[0][0] = "c"
                
                s += "\n".join(["".join(r) for r in b])
                
            elif free%2 == 0 and free >= 4:     
                
                b[0][0] = "c"
                b[1][0] = "."
                b[0][1] = "."
                b[1][1] = "."
                    
                free -= 4
                
                s += fillBoard(rows,cols,b,free,mines)
                
            elif free%2 == 1 and rows > 2 and cols > 2 and free >= 9:
                
                b[0][0] = "."
                b[1][0] = "."
                b[2][0] = "."
                b[0][1] = "."
                b[1][1] = "c"
                b[2][1] = "."
                b[0][2] = "."
                b[1][2] = "."
                b[2][2] = "."
                
                free -= 9
                
                s += fillBoard(rows,cols,b,free,mines)
                
            else:
                s += "Impossible"
                
        elif rows > 1:
            s += "*\n"*mines + ".\n"*(rows-mines-1) + "c"  
        elif cols > 1:
            s += "*"*mines+"."*(cols-mines-1)+"c"  
        else:
            s += "c"
        
        results.append(s)
    return results

def fillBoard(rows,cols,board,free,mines):  
    
    x = 0
    y = 0
    lastX = -1
    lastY = y
    while free > 1 and (lastX != x or lastY != y):
        if board[y][x] == ".":
            freeSquares = []
            
            for x2 in range(max(0,x-1),min(x+2,cols)):
                for y2 in range(max(0,y-1),min(y+2,rows)):
                    if (x2 != x or y2 != y) and board[y2][x2] == "*":
                        freeSquares.append((x2,y2))
                    
            if len(freeSquares) == 2:
                (c1,r1),(c2,r2) = freeSquares            
                board[r1][c1] = "."
                board[r2][c2] = "."
                
                lastX = x
                lastY = y
                free -= 2
                
        x += 1
        if x == cols:
            y += 1
            x = 0
            if y == rows:
                y = 0
    
    x = 0
    y = 0
    while free > 0:

        
        if board[y][x] == ".":
            freeSquares = []
            
            for x2 in range(max(0,x-1),min(x+2,cols)):
                for y2 in range(max(0,y-1),min(y+2,rows)):
                    if (x2 != x or y2 != y) and board[y2][x2] == "*":
                        freeSquares.append((x2,y2))
                    
            if len(freeSquares) == 1:
                (c1,r1), = freeSquares
                board[r1][c1] = "."
                free -= 1
                
        x += 1
        if x == cols:
            y += 1
            x = 0
            if y == rows:
                y = 0
        
    return "\n".join(["".join(r) for r in board])
    
    
question = "C"
roundNumber = "1"
name = "large"

inputName = question + "-" + name + ".in"
outputName = question + "-" + name + ".out"

testCases, data = readInput(inputName)
writeOutput(solve(data),outputName)


    