
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
inFile = open('test.in', 'r')
inFile = open('/Users/quentinbramas/Downloads/A-small-attempt0.in', 'r')
#inFile = open('/Users/quentinbramas/Downloads/A-large.in', 'r')

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

def pgcd(a,b):
    while b != 0:
        a,b=b,a%b
    return a

def doCase(case):
	P, Q = [int(x) for x in inFile.readline().split('/')]
	
	Max = 1 << 40

	p = pgcd(P, Q)
	P = P//p
	Q = Q//p
	#print(str(P)+"/"+str(Q))

	factor = Max / Q
	if Q * factor != Max:
		out("impossible")
		return
	P *= factor
	#print(str(P)+"/"+str(Max))
	out(str(40 - int(math.floor(math.log(P, 2)))))







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