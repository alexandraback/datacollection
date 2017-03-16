
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
inFile = open('C-test.in', 'r')
#inFile = open('C:/Users/quentin/Downloads/C-small-attempt1.in', 'r')
#inFile = open('C:/Users/quentin/Downloads/C-large.in', 'r')

def main():
	initBaseMult()
	T = int(inFile.readline())
	startTime = time.clock()
	for case in range(1,T+1):
		out("Case #{}: ".format(case))
		doCase(case)
		out("\n")

		



def out(m):
	outFile.write(m)
	sys.stdout.write(m)

def diviseur(n):
	if n == 2 or n == 3: return None
	if n%2 == 0: return 2
	if n < 9: return None
	if n%3 == 0: return 3
	r = int(n**0.5)
	f = 5
	while f <= r:
		if n%f == 0: return f
		if n%(f+2) == 0: return f+2
		f +=6
	return None 

baseMult = {}

def initBaseMult():
	for i in range(2, 11):
		baseMult[i] = []
		for j in range(32):
			baseMult[i].append(i**j)

def inBase(n, b):
	r = 0
	for i in range(len(n)):
		r += int(n[i]) * baseMult[b][len(n) - i -1]
	return r

B = range(2, 11)

def binInc(n):
	n = inBase(n[:-1], 2)
	return ("{0:b}".format(n + 1)) + '1'

def doCase(case):
	N, J = [int(i) for i in inFile.readline().split()]
	n = '0'*(N-2)
	n = '1'+n+'1'
	print()
	out('\n')
	while J > 0:
		ok = True
		div = []
		for b in B:
			d = diviseur(inBase(n, b))
			if d == None:
				print(n+' Prime')
				ok = False
				break
			else:
				div.append(str(d))
		if ok :
			out(n+' ')
			out(' '.join(div))
			out('\n')
			J -= 1
		n = binInc(n)





def debugln(m):
	debug(m)
	debug('\n')

def debug(m):
	if debugv:
		sys.stdout.write(str(m))

if __name__ == '__main__':
	if len(sys.argv) > 1:
		if re.search('d', sys.argv[1]):
			debugv = 1
		if re.search('i', sys.argv[1]):
			inFile = sys.stdin

	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime)) 