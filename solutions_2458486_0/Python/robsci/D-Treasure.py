# -*- coding: utf-8 *-*
from ContestSolver import ContestSolver


def newparseInput(self, filename=None):
	# parses self.data to self.input
	# interprets first line as number of cases
	# splits remainder of self.input into a list of cases
	if (filename):
		self.readInput(filename)
	self.numcases = int(self.data[0][0])
	self.input = []
	currindex = 1
	for icase in range(self.numcases):
		case = []
		if self.specifycasesize:
			inputs = int(self.data[currindex][1]) + 1
			case.append(self.data[currindex])
			currindex += 1
		else:
			inputs = int((len(self.data) - 1) / self.numcases)
		case += self.data[currindex:currindex + inputs]
		self.input.append(case)
		currindex += inputs

ContestSolver.parseInput = newparseInput


def possible(keys, chests, locked, maxtype=200):
	numchests = [0] * maxtype
	numkeys = [0] * maxtype
	for key in keys:
		numkeys[key - 1] += 1
	for ichest in locked:
		numchests[chests[ichest][0] - 1] += 1
		for key in chests[ichest][2:]:
			numkeys[key - 1] += 1
	poss = not any(numkeys[i] < numchests[i] for i in range(maxtype))
	if poss:
		for ichest in locked:
			if numkeys[chests[ichest][0] - 1] == 1 and any(key == chests[ichest][0] for key in chests[ichest][2:]):
				poss = False
				break
	return poss


def findSolution(keys, chests, locked):
	if len(locked) == 0:
		return True, []
	else:
		if possible(keys, chests, locked):
			for ichest in locked:
				if any(key == chests[ichest][0] for key in keys):
					newkeys = [key for key in keys]
					newkeys.remove(chests[ichest][0])
					newkeys += chests[ichest][2:]
					newlocked = [lock for lock in locked]
					newlocked.remove(ichest)
					found, sol = findSolution(newkeys, chests, newlocked)
					if found:
						return True, [ichest] + sol
					if any(key == chests[ichest][0] for key in chests[ichest][2:]):
						break
			return False, []
		else:
			return False, []


def solver(case):
	numchests = case[0][1]
	keys = case[1]
	chests = case[2:]
	locked = [i for i in range(numchests)]
	found, solution = findSolution(keys, chests, locked)
	if found:
		return [chest + 1 for chest in solution]
	else:
		return ["IMPOSSIBLE"]


solution = ContestSolver(solver, nosinglelists=False, specifycasesize=True)
#solution.run("D-test", test=True, ints=True)
solution.run("D-small-attempt1", ints=True)
#solution.run("D-large", ints=True)
