# -*- coding: utf-8 *-*
from ContestSolver import ContestSolver
from math import sqrt


def solver(case):
	r = case[0][0]
	t = case[0][1]
	N = int((0.5 - r + 0.5*sqrt(4*r*r-4*r+1+8*t))/2.0)-1
	while (2*N*N+(2*r-1)*N <= t):
		N += 1
	return [N - 1]


solution = ContestSolver(solver,
	splitlines=True, nosinglelists=True, specifycasesize=False)
#solution.run("A-test", test=True, ints=True)
#solution.run("A-small-attempt0", ints=True)
solution.run("A-large", ints=True)
