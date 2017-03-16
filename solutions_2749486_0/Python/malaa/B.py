# -*- coding: utf-8 -*-
"""
Created on Wed Apr 10 21:58:25 2013

@author: malaa
"""

from copy import deepcopy
import numpy as np
import re

stop = False

def read_input(file_name):
    input = open(file_name).readlines()
    input = [i.strip() for i in input]
#    print input

    T = int(input[0])
    cases = list()

    for t in xrange(T):
        inp = input[t+1].split(' ')
        case = {'x':int(inp[0]), 'y':int(inp[1])}
        cases.append(case)
    return (T, cases)

def get_relation(p1, p2):
    if p1[0] > p2[0] and p1[1] == p2[1]:
        return 'E'
    if p1[0] < p2[0] and p1[1] == p2[1]:
        return 'W'
    if p1[0] == p2[0] and p1[1] > p2[1]:
        return 'N'
    if p1[0] == p2[0] and p1[1] < p2[1]:
        return 'S'

def bfs(x, y):
    q = list([(0, 0, 1, 'X')])
    parent = dict()

    cur = (0, 0, 1, 'X')
    while True:
        # add moves from heaf of queue
        cur = q.pop(0)
#        print cur
        if (cur[0] == x and cur[1] == y):
            break

        # add moves
        next = (cur[0] + cur[2], cur[1])
        if not parent.has_key(next):
            parent[next] = (cur[0], cur[1], 'E')
            q.append((next[0], next[1], cur[2]+1))

        next = (cur[0] - cur[2], cur[1])
        if not parent.has_key(next):
            parent[next] = (cur[0], cur[1], 'W')
            q.append((next[0], next[1], cur[2]+1))

        next = (cur[0], cur[1] + cur[2])
        if not parent.has_key(next):
            parent[next] = (cur[0], cur[1], 'N')
            q.append((next[0], next[1], cur[2]+1))

        next = (cur[0], cur[1] - cur[2])
        if not parent.has_key(next):
            parent[next] = (cur[0], cur[1], 'S')
            q.append((next[0], next[1], cur[2]+1))

    # we are done, print out the path
    path = list()
    cur = (x, y, 'X')
#    print parent
    while True:
#        print cur
        p = parent[(cur[0], cur[1])]
        path.append(p[2])
        cur = p

        if cur[0] == 0 and cur[1] == 0:
            break

    path.reverse()
    path = ''.join(path)
#    print path
    return path


def check_case(case):
    return bfs(case['x'], case['y'])

def check_cases(cases):
    out = list()
    for t in xrange(len(cases)):
        print "Case:", t
        case = cases[t]
        s = check_case(case)
        out.append("Case #%d: %s" % (t+1, s))

    return out


infile = 'B-small-attempt0.in' #'C-example.txt' # 'C-small-attempt1.in'

(T, cases) = read_input(infile)
#print cases
out = check_cases(cases)
print out
#
open(infile + ".out", 'w').write("\n".join(out))

