import math
import sys
sys.setrecursionlimit(10000)

import time

def DeceitfulWar(N, Naomi, Ken):
	NIndex = 0
	KIndex = 0
	while NIndex < N:
		if Naomi[NIndex] < Ken[KIndex]:
			NIndex += 1
		else:
			NIndex += 1
			KIndex += 1
	return KIndex
	

def War(N, Naomi, Ken):
	NIndex = 0
	KIndex = 0
	while KIndex < N:
		if Naomi[NIndex] < Ken[KIndex]:
			NIndex += 1
			KIndex += 1
		else:
			KIndex += 1
	return N - NIndex
	

start_time = time.time()

# inFile = open("input.txt", "r")
inFile = open("D-large.in", "r")
outFile = open("D.out", "w")
T = int(inFile.readline())

for i in range(T):
	N = int(inFile.readline())
	NaomiStr = inFile.readline().split()
	Naomi = [float(s) for s in NaomiStr]
	Naomi.sort()
	KenStr = inFile.readline().split()
	Ken = [float(s) for s in KenStr]
	Ken.sort()

	outFile.write( ("Case #%d: " % (i + 1)))
	outFile.write( str(DeceitfulWar(N, Naomi, Ken)) )
	outFile.write(' ')
	outFile.write( str(War(N, Naomi, Ken)) )
	outFile.write('\n')

print time.time() - start_time, "seconds"
	





# for line in File:
# 	f.append(line.split())
# for i in range(int(f[0][0])):
# 	name = f[i+1][0]
# 	n = int(f[i+1][1])
# 	print "Case #%d:" %(i+1), solve(name, n)