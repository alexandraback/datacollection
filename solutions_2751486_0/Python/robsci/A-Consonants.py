# -*- coding: utf-8 *-*
from ContestSolver import ContestSolver


vowels = ['a', 'e', 'i', 'o', 'u']


def substrings(string, length):
	return [string[i:i + length] for i in range(len(string) - length + 1)]


def allsubstrings(string, n=1):
	out = []
	for i in range(n, len(string) + 1):
		out += substrings(string, i)
	return out


def testconseq(string, n):
	letters = [char for char in string]
	num = 0
	for letter in letters:
		if letter in vowels:
			num = 0
		else:
			num += 1
			if num == n:
				return True
	return False


def solver(case):
	name = case[0][0]
	n = int(case[0][1])
	subs = allsubstrings(name, n)
	nval = 0
	for sub in subs:
		if testconseq(sub, n):
			nval += 1
	return [nval]


solution = ContestSolver(solver,
	splitlines=True, specifycasesize=False, nosinglelists=True)
#solution.run("A-test", test=True)
solution.run("A-small-attempt0")
#solution.run("A-large", watch=True)
