#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

def read_int(f): return int(f.readline().strip())
def read_l_int(f): return [int(e) for e in f.readline().strip().split()]

n_max = 201
solutions = [[None]*n_max for i in range(n_max)]
solutions[100][100] = ''
n_remaining = n_max**2-1

def solve():
    points = {(0,0):''}
    global n_remaining

    i = 1
    while n_remaining:
        new_points = {}
        for p, v in points.iteritems():
            new_ps = [(p[0]+i, p[1], v+'E'), (p[0]-i, p[1], v+'W'),
                      (p[0], p[1]+i, v+'N'), (p[0], p[1]-i, v+'S')]
            for x, y, s in new_ps:
                if abs(x) > 100 or abs(y) > 100: continue
                if (x, y) not in new_points:
                    new_points[(x, y)] = s
        for k, v in new_points.iteritems():
            if solutions[k[0]+100][k[1]+100] == None:
                solutions[k[0]+100][k[1]+100] = v
                n_remaining -= 1
                #print 'Solved', k, 'with', v
        points = new_points
        #print i, n_remaining
        i += 1

    """
    for x in range(-100, 101):
        for y in range(-100, 101):
            if solutions[x+100][y+100] == None:
                print x, y
    """

if __name__ == '__main__':
    if len(sys.argv)<2:
        print 'Syntax', sys.argv[0], 'fname'
        sys.exit(1)

    solve()

    f = open(sys.argv[1])
    n_cases = read_int(f)

    for i_case in range(1, n_cases+1):
        x, y= read_l_int(f)
        print 'Case #%d:'%i_case, solutions[x+100][y+100]
