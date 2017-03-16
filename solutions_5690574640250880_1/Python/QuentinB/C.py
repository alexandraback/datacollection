
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
inFile = open('C-small-attempt11.in', 'r')
inFile = open('C-large.in', 'r')

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

def cobin(k,n):
	#debug(str(k)+" parmi "+str(n)+"\n")
	return math.factorial(n)//(math.factorial(n-k)*math.factorial(k))


def doCase(case):
	R, C, M = [int(x) for x in inFile.readline().split()]
	

	remains = R*C-M
	if 1<remains < 4 and R != 1 and C != 1:
		out("\nImpossible")
		return

	#if R < C:
	#	remainsRoot = min([C, math.ceil(math.sqrt(remains))])
	#else:
	remainsRoot = min([R, C, math.ceil(math.sqrt(remains))])

	#out(str(remains)+'\n')
	#out(str(remainsRoot)+'\n')
	#if min([R, C, math.floor(math.sqrt(remains))]) == 2 and R != 1 and C != 1 and remains%remainsRoot:
	if remainsRoot == 2 and R != 1 and C != 1 and remains%remainsRoot:
		out("\nImpossible")
		return
	if remainsRoot == 3 and R != 1 and C != 1 and remains in [5, 7]:
		out("\nImpossible")
		return

	warning = int(remains%remainsRoot)
	

	lastComplete = (int(remains) - int(remains%remainsRoot)) // int(remainsRoot) - 1
	
	inverse = False
	if R < C:
		inverse = True
		R, C = [C, R]
		
	criticPoint = [int(lastComplete) ,int(remainsRoot - 1) ]
	'''out(str(criticPoint)+'\n')
	out(str(warning)+'\n')
	out(str(remainsRoot)+'\n')'''
	O = []
	first = True
	for r in range(R):
		Or = []
		for c in range(C):
			if (not first) and [r, c] == criticPoint and warning == 1:
				Or.append('*')
			elif c < remainsRoot and remains > 0:
					if first:
						first = False
						Or.append('\nc')
					else:
						Or.append('.')
					remains -= 1
			else:
				Or.append('*')
		O.append(Or)

	if inverse:
		for c in range(C):
			for r in range(R):
				out(str(O[r][c]))
			if c != C -1:
				out('\n')
	else:
		for r in range(R):
			for c in range(C):
				out(str(O[r][c]))
			if r != R -1:
				out('\n')
			

	




	#out(str(count))






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