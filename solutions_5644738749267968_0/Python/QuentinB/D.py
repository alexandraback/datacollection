
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
inFile = open('D-test.in', 'r')
inFile = open('D-small-attempt0.in', 'r')
#inFile = open('D-large.in', 'r')

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
	N = int(inFile.readline())
	Naomi = [float(x) for x in inFile.readline().split()]
	Ken = [float(x) for x in inFile.readline().split()]
	Naomi.sort()
	Ken.sort()

	debugln('')
	debugln(str(Naomi))
	debugln(str(Ken))



	scoreDWar = 0
	worstKen = 0
	i = 0
	while i < N:
		if Naomi[i] > Ken[worstKen]:
			scoreDWar += 1
			worstKen += 1
		i += 1

	
	out(str(scoreDWar))

	scoreWar = 0
	bestKen = N - 1
	i = N - 1
	while i >= 0:
		if Naomi[i] > Ken[bestKen]:
			scoreWar += 1
		else:
			bestKen -= 1
		i -= 1

	out(' '+str(scoreWar))






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