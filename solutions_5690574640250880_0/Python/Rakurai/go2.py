import sys
from pprint import pprint
import copy

def write(st):
    sys.stdout.write(st)
def writecase(i):
    if i == 0:
        print 'i is 0!!!!!!!!!!!!!!!!!'
    write("Case #%d:" % i)

f = open(sys.argv[1])
T = int(f.readline())
        
def change(grid, x, y, c):
    s = list(grid[y])
    s[x] = c
    grid[y] = "".join(s)
    
def mines_near(grid, x, y):
    mines = 0
    if x > 0:
        if y > 0:
            if grid[y-1][x-1] == '*': mines += 1
        if y < len(grid)-1:
            if grid[y+1][x-1] == '*': mines += 1
        if grid[y][x-1] == '*': mines += 1
    if x < len(grid[0])-1:
        if y > 0:
            if grid[y-1][x+1] == '*': mines += 1
        if y < len(grid)-1:
            if grid[y+1][x+1] == '*': mines += 1
        if grid[y][x+1] == '*': mines += 1
    if y > 0:
        if grid[y-1][x] == '*': mines += 1
    if y < len(grid)-1:
        if grid[y+1][x] == '*': mines += 1

    return mines

def reveal(grid, x, y):
    if grid[y][x] != '.':
        return 0

    if grid[y][x] == '.':
        change(grid, x, y, 'r')

    if mines_near(grid, x, y) > 0:
        return 1

    revealed = 1

    if x > 0:
        if y > 0:
            revealed += reveal(grid, x-1, y-1)
        if y < len(grid)-1:
            revealed += reveal(grid, x-1, y+1)
        revealed += reveal(grid, x-1, y)
    if x < len(grid[0])-1:
        if y > 0:
            revealed += reveal(grid, x+1, y-1)
        if y < len(grid)-1:
            revealed += reveal(grid, x+1, y+1)
        revealed += reveal(grid, x+1, y)
    if y > 0:
        revealed += reveal(grid, x, y-1)
    if y < len(grid)-1:
        revealed += reveal(grid, x, y+1)

    return revealed

for t in range(1, T+1):
    line = f.readline()
    parts = line.split()
    R = int(parts[0])
    C = int(parts[1])
    M = int(parts[2])

    grid = ['.'*C for _ in range(R)]
#    grid.append('.'*(C-1) + 'c')
#    pprint(grid)

    mines_placed = 0
    filled_rows = 0
    filled_cols = 0
    row = 0
    col = 0

    # special case
    if M == (R*C-1):
        writecase(t)
        write('\n')
        for r in range(R-1):
            print '*'*C
        print '*'*(C-1) + 'c'
        continue

    while mines_placed <= M:
#        if (C - filled_cols) <= 2 and (R - filled_rows) <= 2:
#            break

        # pick row or column
        filling_row = True
        to_place = C - filled_cols

        if to_place > (R - filled_rows):
            filling_row = False
            to_place = R - filled_rows

#        if t == 210:
#            print filling_row, to_place, filled_rows, filled_cols
            
#        if to_place == (M - mines_placed):
#            if (filling_row and C - filled_cols <= 2) or (not filling_row and R - filled_rows <= 2):
#                break
        if to_place > (M - mines_placed):
            # fill the rest, stay two away from the edges
            for y in range(filled_rows, R-2): # 0, 1
                for x in range(filled_cols, C-2): # 1
                    if mines_placed < M:
                        change(grid, x, y, '*')
                        mines_placed += 1
            break
        elif filling_row:
            grid[filled_rows] = '*'*C
            filled_rows += 1
            mines_placed += to_place
        else:
            for y in range(R):
                change(grid, filled_cols, y, '*')
            filled_cols += 1

            mines_placed += to_place


    writecase(t)
#    write('%d %d %d' % (R, C, M))
    write('\n')
    remaining = mines_placed - M
    free_spots = R*C-M
    if remaining:
        print 'Impossible'
#       print 'Impossible', M, R*C, R*C-M
#        for r in range(R):
#            print grid[r]
    else:
#        print 'revealing'
        revealed = reveal(copy.deepcopy(grid), C-1, R-1)
#        print 'revealed %d' % revealed
        if revealed != R*C-M:
            print 'Impossible'
#            print 'Impossible', M, R*C, R*C-M
        else:
            change(grid, C-1, R-1, 'c')
            for r in range(R):
                print grid[r]

f.close()