'''
Created on Apr 12, 2013

@author: Andrew
'''

sample = '''6
XXXT
....
OO..
....

XOXT
XXOO
OXOX
XXOO

XOX.
OX..
....
....

OOXX
OXXX
OX.T
O..O

XXXO
..O.
.O..
T...

OXXX
XO..
..O.
...O'''.split('\n')

sample_o = '''Case #1: X won
Case #2: Draw
Case #3: Game has not completed
Case #4: O won
Case #5: O won
Case #6: O won'''.split('\n')

def raw_input_test():
    global sample
    if len(sample) == 0:
        return ''
    ret = sample[0]
    sample = sample[1:]
    return ret

def wins(grid, char):
    diag1 = [grid[0][0], grid[1][1], grid[2][2], grid[3][3]]
    diag2 = [grid[0][3], grid[1][2], grid[2][1], grid[3][0]]
    
    for row in grid + zip(*grid) + [diag1, diag2]:
        row = ''.join(row)
        row = row.replace('T',char)
        
        if row.count(char) == 4:
            return True
    return False 
    
def draw(grid):
    for row in grid:
        if '.' in row:
            return False
    return True

def _print(x):
    print x
def print_test(x):
    global sample_o
    s = sample_o[0]
    assert s == x
    sample_o = sample_o[1:]
    print x

getline = raw_input #raw_input_test
printline = _print #print_test

 
num_cases = int(getline())

for case_num in xrange(1,num_cases + 1):
    grid = []
    for t in xrange(4):
        grid.append(list(getline().strip()))
    getline()
    msg = "Game has not completed"
    x = wins(grid, 'X')
    o = wins(grid, 'O')
    d = draw(grid)
    if x and not o:
        msg = 'X won'
    elif o:
        msg = "O won"
    elif d:
        msg = "Draw"
    printline("Case #{0}: {1}".format(case_num, msg))