# -*- coding: utf-8 *-*
from ContestSolver import ContestSolver
from fractions import gcd


def possible(P, Q, n):
	return (Q == gcd(P * (2**n), Q))


def generations(P, Q, n):
	# assumes P, Q, n is possible
	if (P == Q):
		return n
	elif 2*P/Q >= 1:
		return n - 1
	else:
		return generations(2*P, Q, n - 1)


def solver(case):
	P, Q = map(int, case[0][0].split('/'))
	if (P == 0 or not possible(P, Q, 40)):
		return ['impossible']
	else:
		return [40 - generations(P, Q, 40)]


solution = ContestSolver(solver)
#solution.run("A-test", ints=False, test=True, watch=False)
solution.run("A-small-attempt0", ints=False)
#solution.run("A-large", ints=False, watch=False)
