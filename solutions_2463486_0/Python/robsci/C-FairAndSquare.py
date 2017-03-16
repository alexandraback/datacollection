# -*- coding: utf-8 *-*
from ContestSolver import ContestSolver
from math import log10, sqrt


def palindrome(number):
	strnum = str(number)
	revstrnum = str(number)[::-1]
	return strnum == revstrnum


def digitsToNumber(digits):
	x = 0
	num = len(digits)
	for i in range(num):
		x += digits[i] * pow(10, num - 1 - i)
	return x


def paldigitsToNumber(paldigits, odd):
	revdigits = [dig for dig in paldigits]
	revdigits.reverse()
	if odd:
		revdigits = revdigits[1:]
	return digitsToNumber(paldigits + revdigits)


def getpartPalindromes(paldigits, odd, level):
	palindromes = []
	if level == 1:
		for i in range(10):
			newdigs = paldigits[:-1] + [i]
			if newdigs[0] != 0:
				palindromes.append(paldigitsToNumber(newdigs, odd))
		return palindromes
	else:
		for i in range(10):
			newdigs = paldigits[:-level] + [i] + paldigits[1 - level:]
			if newdigs[0] != 0:
				palindromes += getpartPalindromes(newdigs, odd, level - 1)
		return palindromes


def getPalindromes(a, b):
	palindromes = []
	minn = int(log10(a)) + 1
	maxn = int(log10(b)) + 1
	for n in range(minn, maxn + 1):
		palindromes += getpartPalindromes([1]*((n + 1) / 2), n % 2 == 1, (n + 1) / 2)
	return [number for number in palindromes if number >= a and number <= b]


def solver(case):
	minrange = case[0][0]
	maxrange = case[0][1]
	palindromes = getPalindromes(sqrt(minrange), sqrt(maxrange))
	squares = [p * p for p in palindromes]
	counter = 0
	for square in squares:
		if palindrome(square):
			counter += 1
	return [counter]

solution = ContestSolver(solver)
#solution.run("C-test", test=True, ints=True)
solution.run("C-small-attempt0", ints=True)
#solution.run("C-large", ints=True)
