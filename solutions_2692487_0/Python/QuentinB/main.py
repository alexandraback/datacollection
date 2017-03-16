
import sys
import time
import operator
import math


timeit = 1
debugv = 0
startTime = 0

outFile = open('output.txt', 'w')
inFile = sys.stdin
#inFile = open('in.in', 'r')

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
	A , N = [int(x) for x in inFile.readline().split()]
	Motes = [int(x) for x in inFile.readline().split()]

	Motes.sort()
	i = 0
	while i<N and A>Motes[i]:
		A += Motes[i]
		i += 1
	if i >= N:
		out("0")
		return;
	if i == N-1:
		out("1")
		return;
	Count = 0
	Motes = Motes[i:]
	N = N - i
	while N > 0:
		debug(str(Motes)+"\n")


		n = 0
		nA = A + A - 1 
		debug("test "+str(nA)+"  , n="+str(Motes[n])+"\n")
		while n < N and nA <= Motes[n]:
			nA += nA - 1
			i = 0
			n += 1
			while i <= n-1 and nA > Motes[i]:
				nA += Motes[i]
				i += 1
			#debug("test "+str(nA)+"  , n="+str(Motes[n])+"\n")
		if n >= N:
			out(str(Count+n))
			return

		i = n
		while i<N and nA>Motes[i]:
			nA += Motes[i]
			i += 1
		Motes = Motes[i:]
		N = N - i
		A = nA
		Count += n+1
		debug(str(A)+" , "+str(Count)+"\n")
	#debug("pas fini "+str(A)+" - "+str(Motes[i:]))
	out(str(Count))
	







def debug(m):
	if debugv:
		sys.stdout.write(m)

if __name__ == '__main__':
	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime))