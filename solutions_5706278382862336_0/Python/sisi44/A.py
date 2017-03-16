from fractions import gcd

def isTwo(a):
	if a == 1:
		return 0
	if a % 2 == 1:
		return -1
	else:
		m = isTwo(a/2)
		if m != -1:
			return m+1
		else:
			return -1


def solve():
	#f = open("in.txt", 'r')
	f = open("A-small-attempt1.in.txt", 'r')
	T = int(f.readline())
	for t in range(T):
		[P, Q] = [int(k) for k in f.readline()[:-1].split('/')]
		G = gcd(P,Q)
		Ps = P/G
		Qs = Q/G
		a = isTwo(Qs)
		if a == -1:
			print "Case #%i:" % (t+1), 'impossible'
		else:
			rd = Qs/2
			index = 1
			for i in range(1, a+1):
				if Ps >= rd:
					index = i
					break 
				rd = rd/2
			print "Case #%i:" % (t+1), index


solve()