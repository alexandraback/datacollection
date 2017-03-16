#!/usr/bin/python3

from sys import stdin

def drop_row(row):
	field[row: row + 1] = []

def drop_column(column):
	for row in range(len(field)):
		field[row][column: column + 1] = []

def get_column_value(column):	
	return max([field[i][column] for i in range(len(field))])

def get_row_value(row):
	return max(field[row])

def get_min_value():
	minv = None
	for row in range(len(field)):
		for column in range(len(field[row])):
			if minv is None or field[row][column] < minv:
				minv = field[row][column]
				_row = row
				_column = column
	if minv is not None:
		return (_row, _column)
	else:
		return (None, None)


def solve():
	while True:
		x, y = get_min_value()
		if x is None:
			return 'YES'
		if get_row_value(x) == field[x][y]:
			drop_row(x)
			continue
		if get_column_value(y) == field[x][y]:
			drop_column(y)
			continue
		return 'NO'

T = int(stdin.readline())
for i in range(T):
	n, m = map(int, stdin.readline().split())
	field = [ list(map(int, stdin.readline().split())) for i in range(n) ]
	print('Case #%d: %s' % (i + 1, solve()))