
import sys
import time
import operator
import math
import re

timeit = 1
debugv = 0
startTime = 0

outFile = open('output.txt', 'w')
inFile = sys.stdin
inFile = open('A-test.in', 'r')
inFile = open('C:/Users/quentin/Downloads/A-small-attempt0 (1).in', 'r')
#inFile = open('C:/Users/quentin/Downloads/A-large.in', 'r')

def main():
	T = int(inFile.readline())
	startTime = time.clock()
	for case in range(1,T+1):
		out("Case #{}: ".format(case))
		doCase(case)
		out("\n")

		



def out(m):
	outFile.write(m)
	sys.stdout.write(m)

def doCase(case):
	S = inFile.readline()
	S = S.replace('\n','')

	L = {}
	for s in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
		L[s] = 0
	for s in S:
		L[s] += 1

	D = {}
	for i in range(10):
		D[i] = 0

	if L['Z'] > 0:
		D[0] += L['Z']
		L['E'] -= L['Z']
		L['R'] -= L['Z']
		L['O'] -= L['Z']
		L['Z'] = 0

	if L['X'] > 0:
		D[6] += L['X']
		L['S'] -= L['X']
		L['I'] -= L['X']
		L['X'] = 0

	if L['S'] > 0:
		D[7] += L['S']
		L['E'] -= 2 * L['S']
		L['V'] -= L['S']
		L['N'] -= L['S']
		L['S'] = 0

	if L['V'] > 0:
		D[5] += L['V']
		L['F'] -= L['V']
		L['I'] -= L['V']
		L['E'] -= L['V']
		L['V'] = 0

	if L['G'] > 0:
		D[8] += L['G']
		L['E'] -= L['G']
		L['I'] -= L['G']
		L['H'] -= L['G']
		L['T'] -= L['G']
		L['G'] = 0
		
	if L['I'] > 0:
		D[9] += L['I']
		L['N'] -= 2 * L['I']
		L['E'] -= L['I']
		L['I'] = 0

	if L['H'] > 0:
		D[3] += L['H']
		L['E'] -= 2 * L['H']
		L['R'] -= L['H']
		L['T'] -= L['H']
		L['H'] = 0

	if L['N'] > 0:
		D[1] += L['N']
		L['O'] -= L['N']
		L['E'] -= L['N']
		L['N'] = 0

	if L['W'] > 0:
		D[2] += L['W']
		L['T'] -= L['W']
		L['O'] -= L['W']
		L['W'] = 0

	if L['F'] > 0:
		D[4] += L['F']

	for i in range(10):
		for j in range(D[i]):
			out(str(i))







def debug(m):
	if debugv:
		sys.stdout.write(m)

if __name__ == '__main__':
	if len(sys.argv) > 1:
		if re.search('d', sys.argv[1]):
			debugv = 1
		if re.search('i', sys.argv[1]):
			inFile = sys.stdin

	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime)) 