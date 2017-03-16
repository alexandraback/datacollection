#file('C-large-practice.in').read()
import itertools
#

def processAllInput(text, toFile = False):
    fileName = text
    if toFile:
        text = file(fileName).read()
    finalResult = []
    numTests = int(text.split('\n')[0])
    lines = text.split('\n')
    for i in range(numTests):
        #Problem-specific code starts here############
        
        message = lines[i+1]        
        rows, cols, mines = map(int, message.split())
        possible = True #FIX
        
        solution = [['*' for _ in range(cols)] for _ in range(rows)]         
        if rows*cols-mines <=1:
            solution[0][0] = 'c'
            possible = True
        elif cols is 1:
            for y in range(rows*cols-mines):
                solution[y][0] = '.'
            solution[0][0] = 'c'
            possible = True
        elif rows is 1:
            for x in range(rows*cols-mines):
                solution[0][x] = '.'
            solution[0][0] = 'c'
            possible = True
        elif rows*cols-mines is 2:
            possible=False
        else:
            newrows = rows
            newcols = cols
            solution = [['.' for _ in range(cols)] for _ in range(rows)]         

            minesLeft = mines
            while minesLeft >= min(newrows, newcols):
                if newrows < newcols:#eliminate a column
                    for y in range(newrows):
                        solution[y][newcols-1]='*'
                    minesLeft -= newrows
                    newcols -= 1
                else:#eliminate a row
                    for x in range(newcols):
                        solution[newrows-1][x]='*'
                    minesLeft -= newcols
            
                    newrows -= 1
            if minesLeft:
                spots = [(x,y) for x in range(newcols) for y in range (newrows)]
                it = itertools.combinations(spots, minesLeft)

                for spots in it:
                    newboard = deepcopy(solution)
                    for x,y in spots:
                        newboard[y][x] = '*'
                    newboard = placeC(newboard)
                    if works(newboard):
                        break
                if works(newboard):
                    solution = newboard
                    possible = True
                else: possible = False
            else:
                solution = placeC(solution)
                if works(solution):
                    possible = True
                else: possible = False
            #print solution
            

        line="Case #{0}:\nImpossible".format(i+1)
        if possible:
            line = 'Case #{0}:\n{1}'.format(i+1,
                            '\n'.join(map(''.join, solution)))
        
        #Problem-specific code ends here##############
        if not toFile:
            print line
        if toFile:                
            if (i+1)%10 == 0:
                print 'Solved {0} cases'.format(i+1)
        finalResult.append(line)
    if toFile:
        file(fileName.split('.')[0]+'.out', 'w').write('\n'.join(finalResult))

def works(board):
    updated = True
    board = deepcopy(board)
    while updated:
        updated  = False
        for x in range(len(board[0])):
            for y in range(len(board)):
                n = getNeighbors(board, x, y)
                if board[y][x] != 'c' and 'c' in n and '*' not in n:
                    board[y][x] = 'c'
                    updated = True
    for x in range(len(board[0])):
        for y in range(len(board)):
            n = getNeighbors(board, x, y)
            c = board[y][x]
            if c == '.' and 'c' not in n:
                return False
    return True

def placeC(board):
    for x in range(len(board[0])):
        for y in range(len(board)):
            n = getNeighbors(board, x, y)
            c = board[y][x]
            if c == '.' and '*' not in n:
                board[y][x] = 'c'
                return board
    return board

def getNeighbors(board, x, y):
    result = list()
    for dx in range(-1,2):
        for dy in range(-1,2):
            nx, ny = x+dx, y+dy
            if dx == dy and dy == 0:
                continue
            if ny < 0 or ny >= len(board):
                continue
            if nx < 0 or nx >= len(board[0]):
                continue
            result.append(board[ny][nx])
    return tuple(result)

def deepcopy(obj):
    if type(obj) == list:
        return [deepcopy(x) for x in obj]
    return obj
