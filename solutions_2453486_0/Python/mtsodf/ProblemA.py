#! /usr/bin/python
import sys
def solve(tab):


	xWon = playerWon('X')
	oWon = playerWon('O')


	if xWon and oWon:
		return 'Draw'

	if xWon:
		return 'X won'

	if oWon:
		return 'O won'

	if tabFull(tab):
		return 'Draw'


	return 'Game has not completed'


def tabFull(tab):
	for s in tab:
		for l in s:
			if l == '.':
				return False

	return True




						
def playerWon(letter):

	tami = len(tab)
	tamj = len(tab[0])

	#verificar lado
	for i in range(tami - 3):
		for j in range(tamj):
			if (tab[i][j] == letter or tab[i][j] == 'T'):
				tresSeguidas = True
				for k in range(1,4):
					l = tab[i + k][j]
					if l != letter and l !='T':
						tresSeguidas = False
						break
				if tresSeguidas:
					return True

	#verificar outrolado
	for i in range(tami):
		for j in range(tamj - 3):
			if (tab[i][j] == letter or tab[i][j] == 'T'):
				tresSeguidas = True
				for k in range(1, 4):
					l = tab[i][j + k]
					if l != letter and l !='T':
						tresSeguidas = False
						break
				if tresSeguidas:
					return True

		#verificar outrolado
	for i in range(tami - 3):
		for j in range(tamj - 3):
			if (tab[i][j] == letter or tab[i][j] == 'T'):
				tresSeguidas = True
				for k in range(1, 4):
					l = tab[i + k][j + k]
					if l != letter and l !='T':
						tresSeguidas = False
						break
				if tresSeguidas:
					return True

	for i in range(tami - 3):
		for j in range(3,tamj):
			if (tab[i][j] == letter or tab[i][j] == 'T'):
				tresSeguidas = True
				for k in range(1, 4):
					l = tab[i + k][j - k]
					if l != letter and l != 'T':
						tresSeguidas = False
						break
				if tresSeguidas:
					return True

	return False


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

io = IOHelper('A', filenum)


for i in range(io.readCases()):
	tab = []

	s = io.readline()

	while len(s[:-1])!=0:

		line = s[:-1].replace(' ','')
		tab.append(line)
		s = io.readline()





	s = solve(tab)
	io.writesol(s)
