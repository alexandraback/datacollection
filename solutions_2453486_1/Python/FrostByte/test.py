results = ["X won", "O won", "Draw", "Game has not completed"]

def check_victory(x, tx, ty, array):
    
    if tx >= 0:
        array[tx] = array[tx].replace('T', x)

    grid = [[0,0,0,0], [0,0,0,0], [0,0,0,0], [0,0,0,0]] 

    row = []
    column = []
    diagonal = []

    for i in range(0,4):

        for j in range(0,4):
            if array[i][j] == x:
                grid[i][j] = 1

        row.append(0)
        column.append(0)
        diagonal.append(0)

    for i in range(0,4):
        for j in range(0,4):
            row[i] += grid[i][j]
            column[j] += grid[i][j]

        diagonal[0] += grid[i][i]
        diagonal[1] += grid[i][3-i]

    for i in range(0,4):
        if row[i] == 4 or column[i] == 4 or diagonal[i] == 4:
            return 1

    return 0

def compute(array):

    draw = 1
    tx, ty = -1, -1

    for i in range(0,4):
        for j in range(0,4):
            if array[i][j] == 'T':
                tx,ty =  i,j

            if array[i][j] == '.':
                draw = 0

    backup = array[tx]

    if check_victory('X', tx, ty, array) == 1:
        return 0

    array[tx] = backup

    if check_victory('O', tx, ty, array) == 1:
        return 1

    if draw == 1:
        return 2

    return 3

def flush():
    raw_input()


def do_thing(index):

    array = [raw_input() for i in range(0,4)]

    result = compute(array)
    print "Case #%d: %s" % (index + 1, results[result])
    
    if(index + 1 < n):
        flush() 

n = raw_input()
n = int(n)

for i in range(n):
    do_thing(i)

