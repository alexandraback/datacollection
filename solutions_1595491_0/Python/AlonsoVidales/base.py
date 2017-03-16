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

	def getMaxSurprise(self, inNum):
		if inNum > 0:
			if (((inNum % 3) == 0) or ((inNum % 3) > 1.5)):
				return int(ceil(inNum / 3)) + 1
			else:
				return int(ceil(inNum / 3))

		return inNum

	def solve(self):
		ret = []

		for case in self.__cases:
			maxGooglers = 0
			for points in case['googlersPoints']:
				maxValue = int(ceil(points / 3))

				if (maxValue >= case['p']):
					maxGooglers += 1
				elif ((case['surprises'] > 0) and (self.getMaxSurprise(points) >= case['p'])):
					case['surprises'] -= 1
					maxGooglers += 1
					
			ret.append(maxGooglers)

		return ret

	def __init__(self, inLines):
		for count in range(1, int(inLines[0]) + 1):
			lineNumbers = inLines[count].split()
			self.__cases.append({
				'cases': int(lineNumbers.pop(0)),
				'surprises': int(lineNumbers.pop(0)),
				'p': int(lineNumbers.pop(0)),
				'googlersPoints': map(float, lineNumbers)})

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
