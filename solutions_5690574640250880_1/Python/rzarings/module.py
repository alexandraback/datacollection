def openNext(position, grid, direction, down):
    rows = len(grid)
    columns = len(grid[0])
    leftCorner = 0
    rightCorner = 0
    cantMove = 0

    # open neighbors
    # down
    if position[0]+1 < rows:
        grid[position[0]+1][position[1]] = '.'
        leftCorner = rightCorner = 1
    # right
    if position[1]+1 < columns:
        grid[position[0]][position[1]+1] = '.'
        rightCorner += 1
    else:
        direction[0] = 0
        cantMove = 1
    # left
    if position[1] > 0:
        grid[position[0]][position[1]-1] = '.'
        leftCorner += 1
    else:
        direction[0] = 1
        cantMove += 1
    # right corner
    if rightCorner == 2:
        grid[position[0]+1][position[1]+1] = '.'
    # left corner
    if leftCorner == 2:
        grid[position[0]+1][position[1]-1] = '.'
    # ill never move up
    # cant move right nor left
    if cantMove == 2:
        down[0] = 1

def updatePosition(grid, position, direction, down, mines, currentMines):
    rows = len(grid)
    columns = len(grid[0])
    # leggo bitches
    if currentMines - mines == 3 and position[1] > 0 and position[1] < columns - 1 and position[0]+2 < rows:
        position[0] += 1
    elif currentMines - mines == 2 and direction[0] == 0 and position[0] != 0 and position[1] == 2 and position[0]+1 < rows:
        position[1] = columns - 1
        position[0] += 1
    elif currentMines - mines == 2 and direction[0] == 1 and position[0] != 0 and position[1] == columns-3 and position[0]+1 < rows:
        position[1] = 0
        position[0] += 1
    # move right one space
    elif down[0] == 1:
        if position[0]+2 < rows:
            position[0] += 1
    elif direction[0] == 1:
        if position[1]+2 < columns:
            position[1] += 1
        # move down and right
        else:
            position[0] += 1
            position[1] += 1
    else:
        if position[1]-1 > 0:
            # move left
            position[1] -= 1
        else:
            # move left and down
            position[1] -= 1
            position[0] += 1

def printGrid(grid):
    for i in range(len(grid)):
        print grid[i]

def countMines(grid):
    count = 0
    for i in range(len(grid)):
        count += grid[i].count('*')
    return count

def outputImpossible(grid,a,mines):
    string = 'Case #'+str(a)+':\n'+'Impossible\n'
    with open('C:\output.txt', 'a') as f:
        f.write(string)

def outputSuccessful(grid,a,mines):
    string1 = 'Case #'+str(a)+':'
    string2 = ''
    with open('C:\output.txt', 'a') as f:
        f.write(string1)
        for i in range(len(grid)):
            f.write('\n')
            for j in range(len(grid[i])):
                string2 = grid[i][j]
                f.write(string2)
        f.write('\n')

def main():
    with open('C:\input.txt') as f:
        testNo = int(f.readline())
        for a in range(testNo):
            data = f.readline().split() # 0 rows 1 columns 2 mines
            rows = int(data[0])
            columns = int(data[1])
            mines = int(data[2])
            currentMines = rows*columns
            grid = [['*' for x in xrange(columns)] for x in xrange(rows)]
            position = [0,0]
            direction = [1] # 1 right 0 left
            down = [0]
            # first click
            grid[position[0]][position[1]] = '.'
            if currentMines - 1 == mines:
                grid[0][0] = 'c'
                outputSuccessful(grid,a+1,mines)
            else:
                while currentMines > mines:
                    openNext(position, grid, direction, down)
                    currentMines = countMines(grid)
                    if mines == currentMines:
                        grid[0][0] = 'c'
                        outputSuccessful(grid,a+1,mines)
                        #printGrid(grid)
                    if mines > currentMines:
                        outputImpossible(grid,a+1,mines)
                    updatePosition(grid, position, direction, down, mines, currentMines)



if __name__ == '__main__':
    main()
