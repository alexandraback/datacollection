#!/usr/bin/env python
""" Generic template file for Google Code Jam Competition """

#Yes, I know, but is faster to use
from itertools import *

__author__ = "Alonso Vidales"
__email__ = "alonso.vidales@tras2.es"
__date__ = "2012-04-13"

class Problem:
	"""
	This class will contain the code to solve the given problem (I hope...)
	"""
	__lettersMap = {
		' ': ' ',
		'y': 'a',
		'n': 'b',
		'f': 'c',
		'i': 'd',
		'c': 'e',
		'w': 'f',
		'l': 'g',
		'b': 'h',
		'k': 'i',
		'u': 'j',
		'o': 'k',
		'm': 'l',
		'x': 'm',
		's': 'n',
		'e': 'o',
		'v': 'p',
		'z': 'q', # DANGER!!!
		'p': 'r',
		'd': 's',
		'r': 't',
		'j': 'u',
		'g': 'v',
		't': 'w',
		'h': 'x',
		'a': 'y',
		'q': 'z'}

	__cases = []

	def solve(self):
		ret = []

		for case in self.__cases:
			resultText = []
			for count in range(0, len(case)):
				resultText.append(self.__lettersMap[case[count]])

			ret.append(''.join(resultText))

		return ret

	def __init__(self, inLines):
		for count in range(1, int(inLines[0]) + 1):
			self.__cases.append(inLines[count])


#Get the input and give the output
fileLines = []
while True:
	try:
		fileLines.append(raw_input())
	except (EOFError):
		break #end of file reached

problem = Problem(fileLines)
solutions = problem.solve()

count = 0
for solution in solutions:
	count += 1
	print("Case #%d: %s" % (count, solution))
