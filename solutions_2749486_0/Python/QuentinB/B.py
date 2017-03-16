
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
inFile = open('in.in', 'r')

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

def voy(s):
	return s=='a' or s=='e' or s=='i'  or s=='o'  or s=='u'  
def addCount(start,l,end,n):
	c = 0
	c += (start + 1)*(end + 1 + l - n)
	m = end + l - n
	c += m*(m+1)//2
	c -= end*(end+1)//2
	return c

def doCase(case):
	X , Y = [int(x) for x in inFile.readline().split()]
	P = ''
	c = 1
	while True:
		debug(P+'  '+str(X)+','+str(Y)+'\n')
		if math.fabs(X)-c == 0:
			if X>0:
				P += 'E'
			else:
				P += 'W'
			X -= int(math.copysign(c,X))
		elif math.fabs(Y)-c == 0:
			if Y>0:
				P += 'N'
			else:
				P += 'S'
			Y -= int(math.copysign(c,Y))
		elif math.fabs(X)-c > 0:
			if X>0:
				P += 'E'
			else:
				P += 'W'
			X -= int(math.copysign(c,X))
		elif math.fabs(Y)-c > 0:
			if Y>0:
				P += 'N'
			else:
				P += 'S'
			Y -= int(math.copysign(c,Y))
		elif math.fabs(X) > 0:
			if X<0:
				P += 'E'
			else:
				P += 'W'
			X += int(math.copysign(c,X))
		elif math.fabs(Y) > 0:
			if Y<0:
				P += 'N'
			else:
				P += 'S'
			Y += int(math.copysign(c,Y))
		else:
			out(P)
			return
		c+=1
	






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