import math

def solve():
	#f = open("in.txt", 'r')
	f = open("B-small-attempt0.in.txt", 'r')
	T = int(f.readline())
	for t in range(T):
		line = f.readline()
		[C, F, X] = l1 = [float(k) for k in line.split()]
		T = math.floor(max(((X-C)*(2+F)-2*X)/(C*F)+1, 0))
		res =  X/(2+T*F)
		for i in range(int(T)):
			res += C/(2+i*F)

		print "Case #%i:" % (t+1), res

solve()
