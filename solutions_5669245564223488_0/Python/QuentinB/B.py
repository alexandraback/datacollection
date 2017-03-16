
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
inFile = open('/Users/quentinbramas/Downloads/B-small-attempt3.in', 'r')
#inFile = open('/Users/quentinbramas/Downloads/B-large.in', 'r')

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



def pairExists(P, a, b):
	exists = False
	if not a in P:
		P[a] = {}
	else:
		if b in P[a]:
			exists = True
	P[a][b] = True
	return exists



def greaterThan(L, a, b):
	if a in L and b in L[a]:
		return True
	return False
def setGreaterThan(L, a, b):
	if not a in L:
		L[a] = {}
	L[a][b] = True
	if b in L:
		for c in L[b]:
			L[a][c] = True
			for d in L:
				if a in L[d]:
					L[d][c] = True
	for c in L:
		if a in L[c]:
			L[c][b] = True



def totalOrder(L, Letters):
	for ai in range(len(Letters)):
		for bi in range(ai+1, len(Letters)):
			a = Letters[ai]
			b = Letters[bi]
			if not (greaterThan(L, a, b) or greaterThan(L, b, a)):
				for c in Letters:
					if c == a or b == c:
						continue
					if greaterThan(L, a, c) or greaterThan(L, c, a):
						if greaterThan(L, b, c) or greaterThan(L, c, b):
							#print(b+" <> "+a+" by "+c)
							return False
	return True


def countComponent(L, Letters):
	c = 0
	Remains = list(Letters)
	while len(Remains):
		c += 1
		current = Remains.pop()
		for ch in Letters:
			if greaterThan(L, ch, current) or greaterThan(L, current, ch):
				if ch in Remains:
					Remains.remove(ch)
			#	print("remove "+ch)
			#else:
			#	print("keep "+ch)

	return c



def doCase(case):
	N = int(inFile.readline())
	Cars = [x for x in inFile.readline().split()]
	CarsByLetters = {}
	mult = 1

	Letters = []
	L = {}
	P = {}
	closeLetters = {}


	#if c1 > 0 and c1 < len(S) - 1:
	#	if S[c1] in closeLetters and not currentCloseLetters
	#	closeLetters[S[c1]] = True
	fact = {}

	for S in Cars:
		currentCloseLetters = {}
		if S[0] == S[len(S) - 1] and S[0] not in CarsByLetters:
			CarsByLetters[S[0]] = []
		else:
			if S[0] == S[len(S) - 1]:
				if S[0] not in fact:
					fact[S[0]] = 1
				fact[S[0]] += 1
		#CarsByLetters[S[0]].append(S)
		for c1 in range(len(S)):
			if not S[c1] in Letters:
				Letters.append(S[c1])
			if c1 > 0 and S[c1] == S[c1 - 1]:
					continue
			for c2 in range(c1 + 1, len(S)):
				if S[c2] == S[c2 - 1]:
						continue
				if S[c1] == S[c2]:
					out(str(0))
					return
				if greaterThan(L, S[c1], S[c2]):
					out(str(0))
					return
				if pairExists(P, S[c1], S[c2]):
					out(str(0))
					return
				setGreaterThan(L, S[c2], S[c1])
				#print(S[c1]+" < "+S[c2])

	#print(L['i'])
	#print(L['x'])
	#print(L['u'])
	if not totalOrder(L, Letters):
		out(str(0))
		#print("not total order")
		return

	sumFact = 1
	for a in fact:
		sumFact *= math.factorial(fact[a])
	out(str((math.factorial(countComponent(L, Letters))*sumFact)%1000000007))
	#print(sorted(Letters, cmp=greaterThan))
	#for c in sorted(Letters, cmp=greaterThan):



			





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