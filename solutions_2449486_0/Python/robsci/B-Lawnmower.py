# -*- coding: utf-8 *-*
from ContestSolver import ContestSolver


def solver(case):
	rows = case[0][0]
	cols = case[0][1]
	pattern = case[1:]

	rowmaxes = []
	for i in range(rows):
		rowmaxes.append(max(pattern[i]))

	colmaxes = []
	for j in range(cols):
		colmaxes.append(max([row[j] for row in pattern]))

	for i in range(rows):
		for j in range(cols):
			if min(rowmaxes[i], colmaxes[j]) != pattern[i][j]:
				return ["NO"]
	return ["YES"]

solution = ContestSolver(solver, specifycasesize=True, nosinglelists=False)
#solution.run("B-test", test=True, ints=True)
solution.run("B-small-attempt1", ints=True)
#solution.run("B-large", ints=True)
