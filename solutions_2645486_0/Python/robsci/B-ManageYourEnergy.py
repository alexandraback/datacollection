# -*- coding: utf-8 *-*
from ContestSolver import ContestSolver


def maxgain(values, E, R, maxE):
	if len(values) == 1:
		return E * values[0]
	else:
		gain = 0
		for i in range(max(E-maxE+R,0), E+1):
			newgain = maxgain(values[1:],min(maxE,E-i+R),R,maxE) + values[0]*i
			gain = max(gain, newgain)
		return gain


def solver(case):
	E = case[0][0]
	R = min(case[0][1], E)
	#numact = case[0][2]
	values = case[1]
	return [maxgain(values, E, R, E)]


solution = ContestSolver(solver,
	splitlines=True, nosinglelists=False, specifycasesize=False)
#solution.run("B-test", test=True, ints=True)
solution.run("B-small-attempt1", ints=True)
#solution.run("B-large", ints=True, watch=True)
