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

def won(lines, v):
	lines = [l.replace('T', v) for l in lines]
	for c in xrange(4):
		if sum([1 for tt in lines if tt[c] == v]) == 4: return True
	for l in xrange(4):
		if lines[l] == 4 * v: return True
	if lines[0][0] == lines[1][1] == lines[2][2] == lines[3][3] == v: return True
	if lines[0][3] == lines[1][2] == lines[2][1] == lines[3][0] == v: return True
	return False

def has_dot(lines):
	for l in lines:
		if '.' in l: return True
	return False
	
def solve(lines):
	if won(lines, 'X'):
		return 'X won'
	elif won(lines, 'O'):
		return 'O won'
	elif has_dot(lines):
		return 'Game has not completed'
	else:
		return 'Draw'

if __name__ == '__main__':
    C = readint()
    for c in xrange(1, C+1):
		lines = [raw_input(), raw_input(), raw_input(), raw_input()]
		line = solve(lines)
		print 'Case #%d: %s' % (c, line)
		raw_input()