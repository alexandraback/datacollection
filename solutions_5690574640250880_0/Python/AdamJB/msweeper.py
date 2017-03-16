#!/usr/bin/env python

from itertools import combinations

class Cell(object):
	location = (0,0)
	isClicked = False
	isOpen = False
	isBomb = False
	numSidesWithBombs = 0
	topLeft = None
	top = None
	topRight = None
	right = None
	bottomRight = None
	bottom = None
	bottomLeft = None
	left = None

	def setLocation(self, loc):
		self.location = loc
	def setTopLeft(self, node):
		self.topLeft = node
	def setTop(self, node):
		self.top = node
	def setTopRight(self, node):
		self.topRight = node
	def setRight(self, node):
		self.right = node
	def setBottomRight(self, node):
		self.bottomRight = node
	def setBottom(self, node):
		self.bottom = node
	def setBottomLeft(self, node):
		self.bottomLeft = node
	def setLeft(self, node):
		self.left = node

	def setIsBomb(self):
		self.isBomb = True
		if self.topLeft:
			self.topLeft.numSidesWithBombs += 1
		if self.top:
			self.top.numSidesWithBombs += 1
		if self.topRight:
			self.topRight.numSidesWithBombs += 1
		if self.right:
			self.right.numSidesWithBombs += 1
		if self.bottomRight:
			self.bottomRight.numSidesWithBombs += 1
		if self.bottom:
			self.bottom.numSidesWithBombs += 1
		if self.bottomLeft:
			self.bottomLeft.numSidesWithBombs += 1
		if self.left:
			self.left.numSidesWithBombs += 1


	def __str__(self):
		if self.isBomb:
			return "*"
		# elif self.isOpen:
		# 	return str(self.numSidesWithBombs)# + str(self.location)
		elif self.isClicked:
			return "c"
		else:
			return "."


	def __repr__(self):
		return str(self)


def visistAllOpenCells(startCell, openCells):
	if startCell in openCells or startCell is None:
		return
	if startCell.isBomb:
		return

	startCell.isOpen = True
	openCells.append(startCell)
	if startCell.numSidesWithBombs != 0:
		return

	visistAllOpenCells(startCell.topRight, openCells)
	visistAllOpenCells(startCell.top, openCells)
	visistAllOpenCells(startCell.topLeft, openCells)
	visistAllOpenCells(startCell.right, openCells)
	visistAllOpenCells(startCell.left, openCells)
	visistAllOpenCells(startCell.bottomLeft, openCells)
	visistAllOpenCells(startCell.bottom, openCells)
	visistAllOpenCells(startCell.bottomRight, openCells)

def printBoard(mineBoard):
	for row in range(0, len(mineBoard)):
		cols = [str(x) for x in mineBoard[row]]
		print "".join(cols)

def createBoard(mineData):
	numRows = mineData[0]
	numColumns = mineData[1]
	numMines = mineData[2]

	rows = [[Cell() for x in range(0, numColumns)] for i in range(0, numRows)]

	for row in range(0, numRows):
		for col in range(0, numColumns):
			rows[row][col].setLocation((row, col))

	for row in range(0, numRows):
		for col in range(0, numColumns):
			rows[row][col].setLocation((row, col))
			if row > 0:
				rows[row][col].setTop(rows[row-1][col])
				if col > 0:
					rows[row][col].setTopLeft(rows[row-1][col-1])
				if col < numColumns-1:
					rows[row][col].setTopRight(rows[row-1][col+1])
			if row < numRows-1:
				rows[row][col].setBottom(rows[row+1][col])
				if col > 0:
					rows[row][col].setBottomLeft(rows[row+1][col-1])
				if col < numColumns-1:
					rows[row][col].setBottomRight(rows[row+1][col+1])

			if col > 0:
				rows[row][col].setLeft(rows[row][col-1])
			if col < numColumns-1:
				rows[row][col].setRight(rows[row][col+1])

	return rows

def mineLocationCombos(mineData):
	numRows = mineData[0]
	numColumns = mineData[1]
	numMines = mineData[2]

	points = []
	cPoints = []
	# All Possible Ranges for 1 point
	for x in range(0, numRows):
		for y in range(0, numColumns):
			points.append((x, y))

	cPoints = [x for x in combinations(points, r=numMines)]
	# print numRows * numColumns
	# print numMines
	# print len(cPoints)
	return cPoints

def printResult(isImpossible, board):
	caseStr = "Case #" + str(case) + ":"
	if isImpossible:
		print caseStr + "\nImpossible"
	else:
		print caseStr
		printBoard(board)

def checkIsImpossible(mineData, case):
	numRows = mineData[0]
	numColumns = mineData[1]
	numMines = mineData[2]
	expectedOpenCells = (numRows * numColumns) - numMines

	isImpossible = True
	board = None

	# Obvious Case:
	if expectedOpenCells == 0:
		printResult(True, None)
		return
	elif expectedOpenCells == 1:
		# Just get 1 sample board with
		isImpossible = False

	mineCombos = mineLocationCombos(mineData)

	allPoints = []
	# All Possible Ranges for 1 point
	for x in range(0, numRows):
		for y in range(0, numColumns):
			allPoints.append((x, y))

	for minePoints in mineCombos:
		board = createBoard(mineData)
		clickedCell = None
		cellsCanOpen = []

		for point in minePoints:
			x = point[0]
			y = point[1]
			board[x][y].setIsBomb()

		# Find safe place to click
		for point in allPoints:
			x = point[0]
			y = point[1]
			if board[x][y].isBomb or (board[x][y].numSidesWithBombs != 0 and expectedOpenCells != 1):
				continue
			else:
				clickedCell = board[x][y]
				clickedCell.isClicked = True
				break

		if clickedCell:
			visistAllOpenCells(clickedCell, cellsCanOpen)

		if expectedOpenCells == len(cellsCanOpen) or expectedOpenCells == 1:
			isImpossible = False
			break

		# Debug stuff
		# print "Board #: " + str(combo)
		# combo += 1
		# printBoard(board)

	printResult(isImpossible, board)

numCases = int(input())

for case in range(1, numCases+1):
	mineData = [int(i) for i in raw_input().strip().split()]
	checkIsImpossible(mineData, case)




