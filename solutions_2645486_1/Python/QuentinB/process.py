

import sys
import time
import math
import operator

timeit = 1
debugv = 0
f = open('output.txt', 'w')

def out(m):
	f.write(m)
	sys.stdout.write(m)

def main():
	T = int(sys.stdin.readline())
	for case in range(1,T+1):
		out("Case #{}: ".format(case))
		doCase(case)
		out("\n")

def debug(m):
	if debugv:
		sys.stderr.write(m)

def maxG(V,R,E,start,end):
	#print(V)
	if not len(V):
		return 0

	i = 0
	mI = 0
	m = V[i]
	i += 1
	while i < len(V) :
		if V[i] > m:
			m = V[i]
			mI=i
		i += 1
	can = min([start+(mI)*R, E])
	debug(' can '+str(can)+' end :'+str(end))
	debug(' maxe '+str(-end+(len(V)-mI-1)*R + can ))
	debug(' '+str(min( [ -end+(len(V)-mI-1)*R + can , can]) *V[mI] )+' + ')
	take = min( [ -end+(len(V)-mI-1)*R + can , can])
	return take *V[mI] + maxG(V[0:mI],R,E,start,min([end + take, E])- R) + maxG(V[mI+1:],R,E,min([E,can-take+R]),end)

def doCase(case):


	E, R, N = [int(n) for n in sys.stdin.readline().split()]
	V = [int(n) for n in sys.stdin.readline().split()]

	m = maxG(V,R,E,E,0)
	out(str(m))



if __name__ == '__main__':
	startTime = time.clock()
	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime))

