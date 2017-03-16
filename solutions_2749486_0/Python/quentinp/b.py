#!/usr/bin/env python3

import sys

def read_input():
    coordinates = []
    with open(sys.argv[1]) as input_file:
        n = int(input_file.readline().strip())
        for l in input_file.readlines():
            x, y = l.strip().split()
            coordinates.append((int(x), int(y)))
            
    assert(len(coordinates) == n)
    return coordinates

coordinates = read_input()

def get_moves_easy(x, y):
    moves = ''
    while x > 0:
        moves += 'WE'
        x -= 1
    while x < 0:
        moves += 'EW'
        x += 1
    while y > 0:
        moves += 'SN'
        y -= 1
    while y < 0:
        moves += 'NS'
        y += 1

    return moves

i = 0
for x, y in coordinates:
    print("Case #{}: {}".format(i+1, get_moves_easy(x, y)))
    i += 1
