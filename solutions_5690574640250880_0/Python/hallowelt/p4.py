#!/usr/bin/python

import sys
import itertools
import string

def minm(n):
    if n % 2 == 0:
        return n/2
    else:
        return n/2 - 1

def onesol(r, c, bombs):
    if bombs >= r*c:
        return None
    board = [[0]*c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if bombs > 0:
                board[i][j] = '*'
            else:
                board[i][j] = '.'
            bombs -= 1
    board[r-1][c-1] = 'c'
    return board

def flip(ar):
    n = len(ar[0])
    m = len(ar)
    newar = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            newar[i][j] = ar[j][i]
    return newar

def solvething(r, c, free):
    if free == 1:
        return [1] + [0] * (r-1)
    m = min(minm(free), c)
    rowsofm = free/m

    if free % m == 1:
        if m < 3:
            return None
        return [m]*(rowsofm-1) + [m-1] + [2] + [0] * (r-rowsofm-1)
    elif free % m == 0:
        return [m]*rowsofm + [0]*(r-rowsofm)
    else:
        return [m]*rowsofm + [free % m] + [0] * (r-rowsofm-1)

def solve(r, c, free):
    guide = solvething(r, c, free)
    board = [[0]*c for _ in range(r)]
    for blank,i in zip(guide, itertools.count()):
        for j in range(c):
            if j < blank:
                board[i][j] = '.'
            else:
                board[i][j] = '*'
    board[0][0] = 'c'
    return board

def multisol(r, c, bombs):
    free = r*c - bombs
    if free in [2, 3, 5, 7]:
        return None
    if (r == 2 or c == 2) and bombs % 2 == 1 and free > 1:
        return None
    if r < c:
        return flip(solve(c, r, free))
    else:
        return solve(r, c, free)

def findboard(r, c, bombs):
    if r == 1 or c == 1:
        return onesol(r, c, bombs)
    else:
        return multisol(r, c, bombs)

def printboard(r, c, bombs):
    board = findboard(r, c, bombs)
    if board is None:
        print 'Impossible'
        return
    for ar in board:
        print string.join(ar, '')

cases = int(sys.stdin.readline())

for casenum in range(1, cases+1):
    r,c,bombs = [int(i) for i in sys.stdin.readline().split()]
    print 'Case #{}:'.format(casenum)
    printboard(r, c, bombs)
    
