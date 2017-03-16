#!/usr/bin/env python3

#invoke Lane
from collections import defaultdict

"""
Not even gonna try for the long input (yet)
"""
players = ["RICHARD", "GABRIEL"]
ominoes_str = """
x
----
xx
----
xxx
----
xx
x
----
xxxx
----
xx
xx
----
xx
 xx
----
x
xx
x
----
xxx
x
"""

def pad(list_to_pad, pad_length, pad_element):
    return list_to_pad + [pad_element] * (pad_length - len(list_to_pad))

def parse_omino(omino_str):
    N = omino_str.count("x")
    rows = omino_str.strip().split("\n")
    num_rows = len(rows)
    num_cols = max( ( len(row) for row in rows ) )
    matrix = [ pad([ x == "x" for x in row ], num_cols, False) for row in rows ]
    return N,matrix

def render(omino):
    return "\n".join([ "".join([ "x" if el else "." for el in row ]) for row in omino ])

ominoes = []
for omino_str in ominoes_str.split("----"):
    n,omino = parse_omino(omino_str)
    ominoes += [omino]

def invert(omino):
    return [ omino[x] for x in range(len(omino) - 1, -1, -1) ] 

def rotate(omino):
    num_rows = len(omino)
    num_cols = len(omino[0])
    new_omino = [ [False]*num_rows for row in range(num_cols) ]
    for r in range(num_rows):
        for c in range(num_cols):
            new_c = num_rows - 1 - r
            new_r = c
            new_omino[new_r][new_c] = omino[r][c]
    return new_omino

def all_rotations(omino):
    r_1 = rotate(omino)
    r_2 = rotate(r_1)
    r_3 = rotate(r_2)
    return [omino, r_1, r_2, r_3]

def gen_all_ominoes(ominoes):
    inverted_ominoes = [ invert(omino) for omino in ominoes ]
    return [ rotation for omino in (ominoes + inverted_ominoes) for rotation in all_rotations(omino)]

all_ominoes = gen_all_ominoes(ominoes)
rendered_ominoes = [ render(omino) for omino in all_ominoes ]
rendered_set = set(rendered_ominoes)

ominoes_of_size = defaultdict(list)
for omino_str in rendered_set:
    n, omino = parse_omino(omino_str)
    ominoes_of_size[n] += [omino]

class Grid:
    def __init__(self, num_rows, num_cols):
        self.grid = [ [False] * num_cols for row in range(num_rows) ]
        self.space_left = num_rows * num_cols

    def can_place(self, omino, r, c):
        if r + len(omino) > len(self.grid):
            return False
        if c + len(omino[0]) > len(self.grid[0]):
            return False
        for omino_r in range(len(omino)):
            row = omino[omino_r]
            for omino_c in range(len(row)):
                elem = omino[omino_r][omino_c]
                if elem:
                    if self.grid[r+omino_r][c+omino_c]:
                        return False
        return True

    def place(self, omino, r, c):
        if not self.can_place(omino, r, c):
            return False
        for omino_r in range(len(omino)):
            row = omino[omino_r]
            for omino_c in range(len(row)):
                elem = omino[omino_r][omino_c]
                if elem:
                    assert not self.grid[r+omino_r][c+omino_c]
                    self.grid[r+omino_r][c+omino_c] = True
                    self.space_left -= 1
        return True

    def unplace(self, omino, r, c):
        for omino_r in range(len(omino)):
            row = omino[omino_r]
            for omino_c in range(len(row)):
                elem = omino[omino_r][omino_c]
                if elem:
                    assert self.grid[r+omino_r][c+omino_c]
                    self.grid[r+omino_r][c+omino_c] = False
                    self.space_left += 1
    def all_moves(self,ominoes):
        results = []
        for r in range(len(self.grid)):
            row = self.grid[r]
            for c in range(len(row)):
                for omino in ominoes:
                    if self.can_place(omino, r, c):
                        results.append((omino,r,c))
        return results

    def can_fill(self, ominoes):
        if self.space_left == 0:
            return True
        can_fill = False
        for (omino,r,c) in self.all_moves(ominoes):
            self.place(omino,r,c)
            if self.can_fill(ominoes):
                can_fill = True
            self.unplace(omino,r,c)
            if can_fill:
                break
        return can_fill

def play_game(X, R, C):
    grid = Grid(R, C)
    ominoes_in_play = ominoes_of_size[X]
    for p1_choice in ominoes_in_play:
        #print(players[0] + " chooses:\n" + render(p1_choice))
        p2_first_moves = grid.all_moves(all_rotations(p1_choice) + all_rotations(invert(p1_choice)))
        p2_can_win_here = False
        for (omino,r,c) in p2_first_moves:
            grid.place(omino,r,c)
            if grid.can_fill(ominoes_in_play):
                p2_can_win_here = True
            grid.unplace(omino,r,c)
            if p2_can_win_here:
                break
        if not p2_can_win_here:
            return players[0]
    return players[1]

T = int(input())
for t in range(T):
    X, R, C = [ int(val) for val in input().split(" ") ]
    print("Case #" + str(t+1) + ": " + play_game(X, R, C))
