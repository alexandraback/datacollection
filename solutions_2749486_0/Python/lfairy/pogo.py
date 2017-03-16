#!/usr/bin/env python3

from collections import namedtuple
import sys

N, S, W, E = 'NSWE'
deltas = [
        (N, lambda x, y, n: (x, y+n)),
        (S, lambda x, y, n: (x, y-n)),
        (W, lambda x, y, n: (x-n, y)),
        (E, lambda x, y, n: (x+n, y))
        ]

forward_deltas = dict(deltas)

reverse_deltas = {
        N: forward_deltas['S'],
        S: forward_deltas['N'],
        W: forward_deltas['E'],
        E: forward_deltas['W']
        }

Cell = namedtuple('Cell', 'steps from_dir')

def generate(limit):
    table = {}
    last_row = [((0, 0), Cell(0, None))]
    table.update(last_row)
    for steps in range(1, limit+1):
        last_row = iterate(table, last_row, steps)
        print('Generating', steps, file=sys.stderr)
    return table

def iterate(table, last_row, steps):
    new_row = []
    for (x, y), cell in last_row:
        for direction, move in deltas:
            new_pos = move(x, y, steps)
            if new_pos not in table or steps < table[new_pos].steps:
                new_cell = Cell(steps, direction)
                table[new_pos] = new_cell
                new_row.append((new_pos, new_cell))
    return new_row

TABLE = generate(30)

def lookup(x, y):
    pos = (x, y)
    result = []
    while pos != (0, 0):
        steps, from_dir = TABLE[pos]
        result.append(from_dir)
        pos = reverse_deltas[from_dir](pos[0], pos[1], steps)
    return ''.join(reversed(result))

if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        x, y = map(int, input().split())
        print('Case #{}: {}'.format(i+1, lookup(x, y)))
