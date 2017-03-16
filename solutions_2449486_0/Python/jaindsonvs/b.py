#!/usr/bin/env python
# -*- coding:utf-8 -*-

def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
        res = []
        for _ in xrange(N):
                res.append(foo())
        return res
def readlinearray(foo): return map(foo, raw_input().split())

def pattern_matched(lawn, lawn2, X, Y):
	for x in xrange(X):
		for y in xrange(Y):
			if lawn[x][y] != lawn2[x][y]: return False
	return True

def printt(lawn):
	for l in lawn:
		print l

def can_cut_right(posX, posY, X, Y, lawn):
	for y in xrange(posY, Y):
		if lawn[posX][y] == 2: return False
	return True

def left_is_cut(posX, posY, X, Y, lawn):
	for y in xrange(posY, -1, -1):
		if lawn[posX][y] == 2: return False
	return True
	
def cut_right(posX, posY, X, Y, lawn):
	for y in xrange(posY, Y):
		lawn[posX][y] = 1

def can_cut_down(posX, posY, X, Y, lawn):
	for x in xrange(posX, X):
		if lawn[x][posY] == 2: return False
	return True

def up_is_cut(posX, posY, X, Y, lawn):
	for x in xrange(posX, -1, -1):
		if lawn[x][posY] == 2: return False
	return True

def cut_down(posX, posY, X, Y, lawn):
	for x in xrange(posX, X):
		lawn[x][posY] = 1

def solve(lawn, X, Y):
	#printt(lawn)
	lawn2 = [[2 for _ in xrange(Y)] for _ in xrange(X)]
	for x in xrange(X):
		for y in xrange(Y):
			if lawn[x][y] != lawn2[x][y]:
				if can_cut_right(x, y, X, Y, lawn) and left_is_cut(x, y, X, Y, lawn):
					cut_right(x, y, X, Y, lawn2)
				elif can_cut_down(x, y, X, Y, lawn) and up_is_cut(x, y, X, Y, lawn):
					cut_down(x, y, X, Y, lawn2)
				else:
					return 'NO'
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
