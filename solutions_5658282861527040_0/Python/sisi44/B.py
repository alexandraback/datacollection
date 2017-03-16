def solve():
	#f = open("in.txt", 'r')
	f = open("B-small-attempt0.in.txt", 'r')
	T = int(f.readline())
	for t in range(T):
		[A, B, K]= [int(k) for k in f.readline().split()]
		res = 0
		for a in range(A):
			for b in range(B):
				if a & b <= K-1:
					#print (a,b), a&b
					res += 1
		print "Case #%i:" % (t+1), res

solve()