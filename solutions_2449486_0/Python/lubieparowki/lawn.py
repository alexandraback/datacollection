import os, sys
from pprint import *

inFile = None
outFile = None

def printAnswer(case, answer):
	outFile.write('Case #{0}: {1}\n'.format(case+1, answer))


def solveCase(caseNo):
	
	(Y,X) = map(int, inFile.readline().strip().split())
	lawn = []
	for y in range(Y):
		lawn.append( map(int, inFile.readline().strip().split()))

	rowmaxs = [ max(y) for y in lawn ]
	columnmaxs = []

	for x in range(X):
		columnmax = 0
		for y in range(Y):
			if lawn[y][x] > columnmax:
				columnmax = lawn[y][x]

		columnmaxs.append(columnmax)

	# print rowmaxs
	# print columnmaxs

	ans = 'YES'
	for y in range(Y):
		for x in range(X):
			value = lawn[y][x]
			if value < rowmaxs[y] and value < columnmaxs[x]:
				ans = 'NO'

	printAnswer(caseNo, ans)

def main():
	cases = int(inFile.readline().strip())
	for case in range(cases):
		solveCase(case)

if __name__ == '__main__':
	inFile = open('in.txt','rt')
	outFile = open('out.txt', 'wt')
	main()