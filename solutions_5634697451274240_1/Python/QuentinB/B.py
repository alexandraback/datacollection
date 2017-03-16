
import sys
import time
import operator
import math
import re
import heapq
from collections import deque

timeit = 1
debugv = 0
startTime = 0

outFile = open('output.txt', 'w')
inFile = sys.stdin
inFile = open('B-test.in', 'r')
inFile = open('C:/Users/quentin/Downloads/B-small-attempt0.in', 'r')
inFile = open('C:/Users/quentin/Downloads/B-large.in', 'r')
#inFile = open('C:/Users/quentin/Downloads/B-large-practice.in', 'r')

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


def invKey(k):
	return -k

def benefice(i):
	return math.log(i, 2)

def recMax(L):
	m = 0
	for l in L:
		for i in l:
			m = max(m,i)
	return m
import queue
def doCase(case):
	line = inFile.readline()
	if line[-1] == '\n':
		line = line[:-1]
	D = [True if c=='+' else False for c in line]
	flip = 0

	while flip < 100:
		#print(D)


		if not D[len(D) - 1] and D[0]:
			i = 0
			flip += 1
			while i < len(D) and D[i]:
				D[i] = False
				i += 1
		if D[len(D) - 1]:
			i = len(D) - 1
			while i >= 0 and D[i]:
				i -= 1
			if i == -1:
				out(str(flip))
				return
			D = D[:i+1]
			continue
		D2 = []
		i = len(D) - 1
		while i >= 0:
			D2.append(not D[i])
			i-=1
		D = D2
		flip += 1
	


'''	maxId = L[0]

	best = L[0]
	Q = []
	for x in L:
		heapq.heappush(Q,-x)

	swap = 0
	while len(Q):
		x = -heapq.heappop(Q)
		best = min(swap + x , best)
		if x == 1:
			break
		#x -= 1
		#print("best : "+str(best)+" "+str(x)+" "+str(swap)+" "+str(Q))
		heapq.heappush(Q,-math.ceil(x/2))
		heapq.heappush(Q,-math.floor(x/2))
		swap += 1
	out(str(best))

'''
'''	eaten = 0
	swap = 0
	while len(L):

		print(" L[0] - eaten ("+str(L[0] - eaten)+") <= ("+str(math.ceil((L[len(L)-1]  - eaten) / 2))+") math.ceil((L[len(L)-1]  - eaten) / 2) ")
		m = math.ceil(L[0]/()) - eaten

		if L[0] - eaten <= math.ceil((L[len(L)-1]  - eaten) / 2):
			p = L.popleft() - eaten
			eaten += p
			print("eat "+str(p))
			continue
		swap += 1
		print(" swap ")
'''
		


'''Cumul = [0]*1000
			Cumul[0] = P[0]
			for i in range(1, 1000):
				Cumul[i] = P[0] + Cumul[i-1]'''

'''score = 0
			for i in range(1000):
				if P[1] > 0:
					score += 1
					for i in range(99):
						P[i] = P[i+1]'''


'''	Q = []
	for x in L:
		if not -x in Q:
			heapq.heappush(Q,-x)
	heapq.heappush(Q,0)

	M = L[0]
	nbSwap = 0
	L = []	
	nbPrev = 0
	while len(Q):
		x = -heapq.heappop(Q)
		#print(str(x)+" "+str(L))
		if x == 1:
			break
		if len(L) == 0:
			nbPrev += P[x]
			L = [x]
			M = max(M, x)
			continue
		#print("x - L[len(L) - 1] "+str(L[0] - max(x, math.ceil(L[0]/2)))+" > "+str(nbPrev)+"  nbPrev ")
		if L[0] - max(x, math.ceil(L[0]/2)) > nbPrev:
			for i in L:
				P[math.ceil(i/2)] += P[i]
				P[math.floor(i/2)] += P[i]
				if not -math.ceil(i/2) in Q:
					heapq.heappush(Q,-math.ceil(i/2))
				if not -math.floor(i/2) in Q:
					heapq.heappush(Q,-math.floor(i/2))

			if not -x in Q:
				heapq.heappush(Q,-x)
			if x != 0:
				M = x
			else:
				M = 1
			nbSwap+=nbPrev
			nbPrev = 0
			L = []
			continue

		L.append(x)
		nbPrev += P[x]'''

	#print(M)
	#print(nbSwap)

	#out(str(M+nbSwap))


'''	nbSwap = 0
	i = 0
	last = -1
	for n in P:
		if last == -1:
			last = n
			i+=1
			continue

		if 0 < last//2 - i < (last - n) :
			nbSwap += i
			print(str(last)+" can be divided")
			i+=1
		else:
			print(str(last)+" cannot be divided "+str(last//2 - i)+" "+str(last-n))
		
		last = n
		i+=1

	#out(str((1 << (nbSwap ))))
	#out(" ")
	out(str(nbSwap + math.ceil(max(P)/(1 << (nbSwap )))))'''





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