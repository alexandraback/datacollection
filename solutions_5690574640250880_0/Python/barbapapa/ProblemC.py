__author__ = 'barbapapa'

import itertools as itt
import numpy as np
import pickle as p


def read_input(f_name):
    cases = []
    with open(f_name) as f:
        nr_cases = int(f.readline().strip())
        for c in range(nr_cases):
            R, C, M = [int(x) for x in f.readline().strip().split(' ')]
            cases.append((R, C, M))
    return cases


def write_output(f_name, results):
    with open(f_name, 'w') as f:
        for i, r in enumerate(results):
            f.write('Case #'+str(i+1)+':\n')
            for l in r:
                f.write(l+'\n')


def check_grid(adj_mines, grid):
    h, w = adj_mines.shape
    #check if all non-mines are next to a zero square
    for y in range(h):
        for x in range(w):
            if adj_mines[y, x] > 0:
                left = max(0, x-1)
                right = min(w-1, x+1)
                up = max(0, y-1)
                down = min(h-1, y+1)
                if 0 not in adj_mines[up:down+1, left:right+1]:
                    return False
    #check if zeros are adjacent
    visited = 1*(adj_mines != 0)
    to_process = []
    for y in range(h):
        for x in range(w):
            if visited[y, x] == 0:
                to_process.append((y, x))
                grid[y, x] = 'c'
                break
        if len(to_process) > 0:
            break

    while len(to_process) > 0:
        y, x = to_process.pop()
        if visited[y, x] == 0:
            visited[y, x] = 2
            left = max(0, x-1)
            right = min(w-1, x+1)
            up = max(0, y-1)
            down = min(h-1, y+1)
            for next_y in range(up, down+1):
                for next_x in range(left, right+1):
                    if visited[next_y, next_x] == 0 and (next_y, next_x) not in to_process:
                        to_process.append((next_y, next_x))

    if 0 in visited:
        return False
    return True


def grid2txt(grid):
    grid_txt = []
    for row in grid:
        grid_txt.append(''.join([x[0] for x in row]))
    return grid_txt

def solve_case(data):
    R, C, M = data
    print 'Solving ', R, C, M

    if R*C - M == 1:
        grid = np.array(list('*'*R*C)).reshape(R, C)
        grid[0, 0] = 'c'
        return grid2txt(grid)

    empty_grid = np.array(list('.'*R*C)).reshape(R, C)

    for it in itt.combinations(range(R*C), M):
        grid = empty_grid.copy()
        adj_mines = np.zeros((R, C))
        for mine in it:
            grid.ravel()[mine] = '*'
            mine_y = mine // C
            mine_x = mine % C
            left = max(0, mine_x-1)
            right = min(C-1, mine_x+1)
            up = max(0, mine_y-1)
            down = min(R-1, mine_y+1)
            adj_mines[up:down+1, left:right+1] += 1
            adj_mines[mine_y, mine_x] = -10

        if check_grid(adj_mines, grid):
            return grid2txt(grid)
    return ['Impossible']


def create_cache(lower, upper):
    cache = {}
    for R in range(lower, upper+1):
        for C in range(lower, upper+1):
            for M in range(1, R*C-1):
                cache[(R, C, M)] = solve_case((R, C, M))
    p.dump(cache, open('cache.txt', 'w'))

#Code to create the cache:
#create_cache(2, 5)

cache = p.load(open('cache.txt'))
file_name = 'C-small-attempt2'
cases = read_input(file_name+'.in')
solution = []
for case in cases:
    if case in cache:
        solution.append(cache[case])
    else:
        print 'Not in cache: ', case
        solution.append(solve_case(case))
        #print 'Solution: ', solution[-1]
write_output(file_name+'.out', solution)
