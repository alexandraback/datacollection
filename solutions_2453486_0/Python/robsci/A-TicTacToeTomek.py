# -*- coding: utf-8 *-*
from ContestSolver import ContestSolver


def parsegridline(chars):
	line = []
	full = True
	for char in chars:
		if char == 'X':
			line.append([1, 0])
		elif char == 'O':
			line.append([0, 1])
		elif char == 'T':
			line.append([1, 1])
		else:
			line.append([0, 0])
			full = False
	return full, line


def solver(case):
	grid = []
	full = True
	for line in case[0:4]:
		newfull, newline = parsegridline(line[0])
		grid.append(newline)
		full = full and newfull

	for i in range(4):
		result = [1, 1]
		for j in range(4):
			result[0] *= grid[i][j][0]
			result[1] *= grid[i][j][1]
		if result == [1, 0]:
			return ["X won"]
		elif result == [0, 1]:
			return ["O won"]

	for j in range(4):
		result = [1, 1]
		for i in range(4):
			result[0] *= grid[i][j][0]
			result[1] *= grid[i][j][1]
		if result == [1, 0]:
			return ["X won"]
		elif result == [0, 1]:
			return ["O won"]

	result = [1, 1]
	for i in range(4):
		result[0] *= grid[i][i][0]
		result[1] *= grid[i][i][1]
	if result == [1, 0]:
		return ["X won"]
	elif result == [0, 1]:
		return ["O won"]

	result = [1, 1]
	for i in range(4):
		result[0] *= grid[3 - i][i][0]
		result[1] *= grid[3 - i][i][1]
	if result == [1, 0]:
		return ["X won"]
	elif result == [0, 1]:
		return ["O won"]

	if full:
		return ["Draw"]
	else:
		return ["Game has not completed"]

solution = ContestSolver(solver)
#solution.run("A-test", test=True)
solution.run("A-small-attempt0")
#solution.run("A-large-practice")
