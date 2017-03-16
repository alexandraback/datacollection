#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys

def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
        res = []
        for _ in xrange(N):
                res.append(foo())
        return res
def readlinearray(foo): return map(foo, raw_input().split())

def printt(lawn):
    for l in lawn:
        print l

def can_cut_horizontally(posX, posY, X, Y, lawn, exp):
    for y in xrange(0, Y):
        if lawn[posX][y] > exp: return False
    return True
    
def cut_horizontally(posX, posY, X, Y, lawn, exp):
    for y in xrange(0, Y):
        lawn[posX][y] = min(lawn[posX][y], exp)

def can_cut_vertically(posX, posY, X, Y, lawn, exp):
    for x in xrange(0, X):
        if lawn[x][posY] > exp: return False
    return True

def cut_vertically(posX, posY, X, Y, lawn, exp):
    for x in xrange(0, X):
        lawn[x][posY] = min(lawn[x][posY], exp)

def solve(lawn, X, Y):
    #printt(lawn)
    lawn2 = [[100 for _ in xrange(Y)] for _ in xrange(X)]
    for x in xrange(X):
        for y in xrange(Y):
            if lawn[x][y] != lawn2[x][y]:
                exp = lawn[x][y]
                if can_cut_horizontally(x, y, X, Y, lawn, exp):
                    cut_horizontally(x, y, X, Y, lawn2, exp)
                elif can_cut_vertically(x, y, X, Y, lawn, exp):
                    cut_vertically(x, y, X, Y, lawn2, exp)
                else:
                    return 'NO'
                #printt(lawn2)
                #print
    return 'YES'

if __name__ == '__main__':
    C = readint()
    for c in xrange(1, C+1):
        N, M = readlinearray(int)
        lawn = []
        for _ in xrange(N):
            lawn.append(readlinearray(int))
        ans = solve(lawn, N, M)
        print 'Case #%d: %s' % (c, ans)
