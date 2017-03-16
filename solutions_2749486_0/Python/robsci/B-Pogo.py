# -*- coding: utf-8 *-*
from ContestSolver import ContestSolver


def ptok(x, y):
	return str(x) + ',' + str(y)


def ktop(key):
	pos = key.split(',')
	return (int(pos[0]), int(pos[1]))


def posspositions(n, positions=None):
	if n == 0:
		return {ptok(0, 0): ''}
	else:
		if positions:
			startpoints = positions
		else:
			startpoints = posspositions(n - 1)
		endpoints = {}
		for start, path in startpoints.items():
			x, y = ktop(start)
			if ptok(x + n, y) not in endpoints:
				endpoints[ptok(x + n, y)] = path + 'E'
			if ptok(x - n, y) not in endpoints:
				endpoints[ptok(x - n, y)] = path + 'W'
			if ptok(x, y + n) not in endpoints:
				endpoints[ptok(x, y + n)] = path + 'N'
			if ptok(x, y - n) not in endpoints:
				endpoints[ptok(x, y - n)] = path + 'S'
		return endpoints


def newrun(self, filename, ints=False, test=False, watch=False):
	self.parseInput(filename)
	if ints:
		self.integerInputs()
	self.output = []
	posses = [posspositions(0)]
	for icase, case in enumerate(self.input, start=1):
		result, posses = self.solver(case, posses)
		self.output.append(result)
		if watch:
			print icase, self.output[-1]
	if test:
		print self.formatOutput()
	self.writeOutput(filename)


ContestSolver.run = newrun


def solver(case, posses):
	end = ptok(case[0][0], case[0][1])
	for poss in posses:
		if end in poss:
			return [poss[end]], posses

	while (end not in posses[-1]):
		posses.append(posspositions(len(posses), posses[-1]))

	return [posses[-1][end]], posses


solution = ContestSolver(solver,
	splitlines=True, specifycasesize=False, nosinglelists=True)
#solution.run("B-test", test=True, ints=True)
solution.run("B-small-attempt0", ints=True)
#solution.run("B-large", ints=True, watch=True)
