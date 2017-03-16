#! /usr/bin/python
import sys


def solve(h, w, grass):
	x = [-1 for i in range(w)]
	xD = [-1 for i in range(w)]
	y = [-1 for j in range(h)]
	yD = [-1 for j in range(h)]

	for i in range(w):
		themax = -1
		for j in range(h):
			if themax < grass[j][i]:
				themax = grass[j][i]

		xD[i] = themax

	for i in range(h):
		themax = -1
		for j in range(w):
			if themax < grass[i][j]:
				themax = grass[i][j]

		yD[i] = themax


	for i in range(w):
		for j in range(h):
			g = grass[j][i]


			if x[i] == -1 and y[j] == -1:
				if xD[i] > g and yD[j] > g:
					return 'NO'

				elif xD[i] > g:
					if y[j] == -1:
						y[j] = g
					else:
						if y[j] != g:
							return 'NO'
				elif yD[j] > g:
					if x[i] == -1:
						x[i] = g
					else:
						if x[i] != g:
							return 'NO'


			elif x[i] != -1 and y[j] != -1:
				if min(x[i], y[j]) != g:
					return 'NO'

			elif x[i] == -1 and y[j] != -1:
				if y[j] < g:
					return 'NO'
				if y[j] > g:
					if xD[i] > g:
						return 'NO'
					x[i] = g

			else:
				if x[i] < g:
					return 'NO'
				if x[i] > g:
					if yD[j] > g:
						return 'NO'
					y[j] = g

	return 'YES'

	

class IOHelper:

	LIST_FILES = ['-small-practice.in', '-large-practice.in', '-test-practice.in' ]

	def __init__(self, letter, filenum):
		self.letter = letter
		self.inputfile = open(str(letter) + IOHelper.LIST_FILES[filenum], 'r')
		self.outputfile = open(str(letter)+"sol.out", 'w')
		self.i = 1

	def readCases(self):
		return int(self.inputfile.readline())

	def readLines(self, n):
		lines = []
		for i in range(n):
			lines.append(self.readline())
		return lines

	def readline(self):
		return self.inputfile.readline()

	def writesol(self, sol):
		s = 'Case #' + str(self.i) + ': ' + str(sol) + '\n'
		print s
		self.i += 1
		self.write(s)

	def write(self, t):
		self.outputfile.write(t)

	def readInt(self):
		return [int(x) for x in self.readline().split(' ')]

	@staticmethod
	def solution(i, sol):
		return "Case #" + str(i + 1) + ": " + str(sol) + '\n'



filenum = 2
if len(sys.argv) > 1:
	filenum = int(sys.argv[1])

io = IOHelper('B', filenum)


for i in range(io.readCases()):
	grass = []
	h, w = io.readInt()

	for j in range(h):
		grass.append(io.readInt())

	s = solve(h, w, grass)
	print s
	io.writesol(s)

