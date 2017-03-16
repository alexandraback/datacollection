import sys
from copy import deepcopy

def run_row(lawn, row, height):
    new_lawn = deepcopy(lawn)
    for col in range(len(new_lawn[0])):
        h = new_lawn[row][col]
        new_lawn[row][col] = min(height, h)
    return new_lawn

def run_col(lawn, col, height):
    new_lawn = deepcopy(lawn)
    for row in range(len(new_lawn)):
        h = new_lawn[row][col]
        new_lawn[row][col] = min(height, h)
    return new_lawn

def possible(lawn, target):
    return all(i >= j for i, j in zip(
        [i for row in lawn for i in row],
        [i for row in target for i in row]
    ))

def solve(lawn):
    rows = len(lawn)
    cols = len(lawn[0])
    cur_lawn = [[100] * cols for _r in range(rows)]
    heights = sorted(list({i for row in lawn for i in row}), key=lambda x: -x)
    for h in heights:
        for r in range(rows):
            new_lawn = run_row(cur_lawn, r, h)
            if possible(new_lawn, lawn):
                cur_lawn = new_lawn
        for c in range(cols):
            new_lawn = run_col(cur_lawn, c, h)
            if possible(new_lawn, lawn):
                cur_lawn = new_lawn
    if lawn == cur_lawn:
        return 'YES'
    return 'NO'

def line():
    return sys.stdin.readline().rstrip()

for i in range(int(line())):
    h, w = [int(n) for n in line().split()]
    lawn = []
    for _i in range(h):
        row = [int(h) for h in line().split()]
        assert len(row) == w, (w, len(row), row)
        lawn.append(row)
    print('Case #{}: {}'.format(i + 1, solve(lawn)))
