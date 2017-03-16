#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def read_int(f): return int(f.readline().strip())
def read_l_int(f): return [int(e) for e in f.readline().strip().split()]

possible_worlds = []

def simulate(world, N):
    if not N: 
        possible_worlds.append(world)
        return

    x, y = 0, 0
    while (x,y) in world: y += 2
    if y == 0: return simulate(world+[(x, y)], N-1)

    if ((x+1, y-1) in world) and ((x-1, y-1) in world): 
        return simulate(world+[(x, y)], N-1)

    # Two branches
    orig_x, orig_y = x, y
    if (x+1, y-1) not in world:
        while (x+1, y-1) not in world and y > 0:
            x += 1
            y -= 1
        simulate(world+[(x,y)], N-1)

    x, y = orig_x, orig_y
    if (x-1, y-1) not in world:
        while (x-1, y-1) not in world and y > 0:
            x -= 1
            y -= 1
        return simulate(world+[(x,y)], N-1)
 
def solve(N, X, Y):
    global possible_worlds
    res = 0.
    x, y = 0, 0
    possible_worlds = []
    simulate([], N)
    total = len(possible_worlds)
    good = sum((X,Y) in p for p in possible_worlds)
    return float(good)/total

if __name__ == '__main__':
    if len(sys.argv)<2:
        print 'Syntax', sys.argv[0], 'fname'
        sys.exit(1)

    f = open(sys.argv[1])
    n_cases = read_int(f)

    for i_case in range(1, n_cases+1):
        N, X, Y = read_l_int(f)
        print 'Case #%d:'%i_case, solve(N, X, Y)
