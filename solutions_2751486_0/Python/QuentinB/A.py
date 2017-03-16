
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
	L , n = [x for x in inFile.readline().split()]
	n = int(n)
	l = len(L)
	'''g = re.search('[^aeiou]{1,'+str(n)+'}', L)
	debug(str(g.start())+'\n')
	
	out('')'''
	count=0
	start = 0
	lastEnd = 0
	c = 0
	while start < l:
		while start < l and voy(L[start]):
			start += 1
		end = start
		while end < l:
			while end < l and not voy(L[end]):
				end += 1
			if end-start >= n:
				break
			start = end
			while start < l and voy(L[start]):
				start += 1
			end = start
		if end == l and end-start < n:
			break
		vend = end
		while vend < l and voy(L[vend]):
			vend += 1
		count += addCount(start-lastEnd,end-start,l-end,n)
		#count -= c * (1+l-end+end-start-n)
		#c += end-start-n+1
		debug(str(start-lastEnd)+','+str(end-start)+','+str(l-end)+'\n')
		#L = L[end:]
		#l -= end
		start = end
		lastEnd = end + 1 - n
		#start = 0
	out(str(count))






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