
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
	maxW = 100 + 10*10 + 2
	N = int(inFile.readline())
	d = [0]*N
	n = [0]*N
	w = [0]*N
	e = [0]*N
	s = [0]*N
	delta_d = [0]*N
	delta_p = [0]*N
	delta_s = [0]*N
	wall = [0]*(maxW*2)

	for i in range(N):
		d[i], n[i] , w[i], e[i], s[i], delta_d[i], delta_p[i], delta_s[i] = [int(x) for x in inFile.readline().split()]
	for i in range(N):
		e[i] -= 1
	succes = 0
	while max(n) > 0:
		debug(str(n)+'\n')
		for i in range(N):
			if n[i] > 0 and d[i] == 0:
				for j in range(w[i],e[i]+1):
					#debug('j = '+str(j)+'\n')
					if wall[maxW + j] < s[i]:
						succes += 1
						debug(str(i)+' hit j = '+str(j)+'\n')
						break
		for i in range(N):
			if n[i] > 0 and d[i] == 0:
				for j in range(w[i],e[i]+1):
					if wall[maxW + j] < s[i]:
						wall[maxW + j] = s[i]
				n[i] -= 1
				d[i] += delta_d[i]
				w[i] += delta_p[i]
				e[i] += delta_p[i]
				s[i] += delta_s[i]
			if d[i] > 0: 
				d[i] -= 1
	out(str(succes))


	


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