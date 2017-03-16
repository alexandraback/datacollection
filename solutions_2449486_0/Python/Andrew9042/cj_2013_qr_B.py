'''
Created on Apr 12, 2013

@author: Andrew
'''

sample = '''3
3 3
2 1 2
1 1 1
2 1 2
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
1 3
1 2 1
'''.split('\n')

sample_o = '''Case #1: YES
Case #2: NO
Case #3: YES'''.split('\n')

def raw_input_test():
    global sample
    if len(sample) == 0:
        return ''
    ret = sample[0]
    sample = sample[1:]
    return ret

def _print(x):
    print x

def print_test(x):
    global sample_o
    s = sample_o[0]
    assert s == x
    sample_o = sample_o[1:]
    print x

getline = raw_input
printline = _print

#getline = raw_input_test
#printline = print_test


def get_row(grid, x):
    return grid[x]

def get_col(grid, x):
    grid = zip(*grid)
    return list(grid[x])

def check_path(row, level):
    for x in row:
        if x > level:
            return False
    return True

def canmow(grid):
    for row in grid:
        for col_num,e in enumerate(row):
            col = get_col(grid, col_num)
            if not check_path(col, e) and not check_path(row, e):
                return False
    return True


num_cases = int(getline())

for case_num in xrange(1,num_cases + 1):
    N, M = map(int, getline().strip().split(' '))
    grid = []
    for t in xrange(N):
        line = getline().strip().split(' ')
        line = map(int, line)
        grid.append(line)

    msg = 'NO'
    if canmow(grid):
        msg = "YES"
    printline("Case #{0}: {1}".format(case_num, msg))