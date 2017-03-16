
import sys
import time
import operator
import math


timeit = 1
debugv = 1
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

def borneSup(N):
	d = int((- 0.5 + math.sqrt(0.25 + 2 * N)) / 2)
	while d*(d+1)//2 < N:
		d+=1
	while d*(d+1)//2 > N:
		d-=1
	return d

def repartition(n,s):
	i = 0
	r = 0
	p = math.pow(0.5,n)
	while i<s:
		r+=cobin(i,n)*p
		i+=1
	return r

def cobin(k,n):
	#debug(str(k)+" parmi "+str(n)+"\n")
	return math.factorial(n)//(math.factorial(n-k)*math.factorial(k))


def doCase(case):
	N , X , Y = [int(x) for x in inFile.readline().split()]
	borne = borneSup(N)
	if not (borne%2) :
		borne -= 1
	if math.fabs(X)+math.fabs(Y) < borne:
		out('1.0')
		return
	if math.fabs(X)+math.fabs(Y) > borne + 1:
		out('0.0')
		return
	restant = N - (borne*(borne+1))//2
	if restant==0:
		out('0.0')
		return
	if Y < restant - borne :
		out('1.0')
		return
	#debug("restant "+str(restant-Y)+","+str(restant)+"\n")
	out(str(repartition(restant,restant-Y)))
	







def debug(m):
	if debugv:
		sys.stdout.write(m)

if __name__ == '__main__':
	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime))