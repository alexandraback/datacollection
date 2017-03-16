

import sys
import time
import math
import operator

timeit = 1
debugv = 1
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

def test(r,n):
	return 2*n*r-n+2*(n)*(n)

def doCase(case):


	r, t = [int(n) for n in sys.stdin.readline().split()]

	test(r,49)
	test(r,50)
	#math.pi
	delta = (2*r-1)*(2*r-1)+8*(t)
	x2 = ((1-2*r)+math.sqrt(delta))/4
	n = math.floor(x2)
	
	if test(r,n) > t:
		out(str(int(n-1)))
	else:
		out(str(int(n)))

'''	first = 2*r + 1

	r += 2
	n = 1
	while first+2*r + 1 <= t:
		first += 2*r + 1
		r += 2
		n += 1'''



if __name__ == '__main__':
	startTime = time.clock()
	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime))

