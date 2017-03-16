# -*- coding: utf-8 -*- 
import os, sys, copy, time, itertools
import copy

class TooBadException(Exception):
    pass

def _solve(levels, stars):
    if not levels:
        return 0

    solutions = []

    for i in xrange(len(levels)):
        level = levels[i]
        if stars >= level[1]:
            new_levels = copy.copy(levels)
            new_levels.pop(i)
            if level[0] == 'x':
                result = _solve(new_levels, stars + 1)
                if result != None:
                    solutions.append(1 + result)
            else:
                result = _solve(new_levels, stars + 2)
                if result != None:
                    solutions.append(1 + result)

        elif level[0] != 'x' and stars >= level[0]:
            new_levels = copy.copy(levels)
            new_levels[i][0] = 'x'
            result = _solve(new_levels, stars + 1)
            if result != None:
                solutions.append(1 + result)

    if not solutions:
        return None

    solutions = [x for x in solutions if x != None]

    return min(solutions)

def solve(lines):
    # levels[level][rate] = required stars
    levels = [map(int, line.split()) for line in lines]
    stars = 0

    return _solve(levels, stars)

lines = sys.stdin.read().split('\n')
lines.pop()
lines.pop(0)

case = 0
while lines:
    case += 1
    levels = int(lines.pop(0))

    result = solve(lines[:levels])
    if result == None:
        print 'Case #%d: Too Bad' % (case)
    else:
        print 'Case #%d: %d' % (case, result)

    lines = lines[levels:]
