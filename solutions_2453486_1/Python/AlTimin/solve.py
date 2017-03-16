#!/usr/bin/python3

from sys import stdin

n = int(stdin.readline())

def read_field():
	return [ stdin.readline().strip() for i in range(4)]

def valid(field, x, y):
	return 0 <= x < len(field) and 0 <= y < len(field[x]) 

def solve(field):
	d = [ (0, 1), (1, 0), (1, 1), (-1, 1) ]
	for x in range(4):
		for y in range(4):
			for (dx, dy) in d:
				ok = True
				count = { 'T': 0, 'X': 0, 'O': 0, '.' : 0 }
				for i in range(4):
					x1 = x + dx * i
					y1 = y + dy * i
					if not valid(field, x1, y1):
						ok = False 
					else:
						count[field[x1][y1]] += 1
				if not ok:
					continue
				if count['.'] > 1:
					continue
				if count['T'] <= 1 and (count['T'] + count['X'] == 4):
					return 'X won'
				if count['T'] <= 1 and (count['T'] + count['O'] == 4):
					return 'O won'
	dots = sum(map(lambda x: x.count('.'), field)) 
	if dots == 0:
		return 'Draw'
	else:
		return 'Game has not completed'

for i in range(n):
	if i != 0:
		stdin.readline()
	print('Case #%d: ' % (i + 1) + solve(read_field()))