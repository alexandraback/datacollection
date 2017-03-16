
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
inFile = open('C:/Users/quentin/Downloads/C-small-1-attempt4.in', 'r')
#inFile = open('C:/Users/quentin/Downloads/C-large.in', 'r')

def main():
	T = int(inFile.readline())
	startTime = time.clock()
	for case in range(1,T+1):
		out("Case #{}: ".format(case))
		doCase(case)
		out("\n")

		
EPS = 0.0000000001

def k(k):
	return 2*k[0] + k[1]

def out(m):
	outFile.write(m)
	sys.stdout.write(m)

def doCase(case):
	N = int(inFile.readline())
	I = []
	for i in range(N):
		d, m, s = [int(x) for x in inFile.readline().split()]
		for j in range(m): 
			I.append(((360 - d)*(s+j),0))
			I.append(((360 - d + 360)*(s+j)-1, 1))


	if(len(I) <= 2): 
		out(str(0))
		return
	I = sorted(I, key=k)
	#print(I)
	score = 0
	m = 0
	for (i, t) in I:
		if t == 0:
			score += 1
		else:
			score -= 1
		m = max(m, score)
	out(str(len(I)//2 - m))
	return
	t11 = H[0][0] * H[0][1] 
	t12 = t11 + H[0][1] * 360
	#print("1: "+str(t11)+" "+str(t12))
	t21 = H[1][0] * H[1][1] 
	t22 = t21 + H[1][1]  * 360
	#print("2: "+str(t21)+" "+str(t22))
	if t11 < t22 and t21 < t12:
		out(str(0))
		print()
	else:
		out(str(1))
		if(len(H) == 2) and N == 1: 
			out("WTFFF")
			return
	
	

	


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