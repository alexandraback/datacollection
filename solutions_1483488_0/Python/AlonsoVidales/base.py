#!/usr/bin/env python
""" Generic template file for Google Code Jam Competition"""

#Yes, I know, but is faster to use
from itertools import *
from math import *

__author__ = "Alonso Vidales"
__email__ = "alonso.vidales@tras2.es"
__date__ = "2012-04-13"

class Problem:
	"""
	This class will contain the code to solve the given problem (I hope...)
	"""
	__cases = []

	def __rotateNum(self, inNum, inPositions):
		""" Rotates the integer inPositions and returns the result as integer """
		divisor = 10 ** inPositions

		if (inNum < divisor):
			return inNum

		leftPart = int(floor(inNum / divisor))
		rightPart = inNum % divisor

		return (rightPart * (10 ** (len(str(inNum)) - inPositions))) + leftPart

	def solve(self):
		ret = []

		for case in self.__cases:
			recycled = 0
			processed = {}
			for num in range(case['from'], case['to'] + 1):
				for pos in range(1, len(str(num))):
					rotated = self.__rotateNum(num, pos)
					if ((rotated <= case['to']) and (num < rotated)):
						if (processed.get(str(num) + '-' + str(rotated), False) == False):
							processed[str(num) + '-' + str(rotated)] = True
							recycled += 1

			ret.append(recycled)

		return ret

	def __init__(self, inLines):
		for count in range(1, int(inLines[0]) + 1):
			lineNumbers = inLines[count].split()
			self.__cases.append({
				'from': int(lineNumbers[0]),
				'to': int(lineNumbers[1])})

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
