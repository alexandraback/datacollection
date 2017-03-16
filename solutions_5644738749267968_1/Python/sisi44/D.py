
def solve():
	#f = open("in.txt", 'r')
	f = open("D-large.in.txt", 'r')
	T = int(f.readline())
	for t in range(T):
		N = int(f.readline())
		line = f.readline()
		l1 = [float(k) for k in line.split()]
		line = f.readline()
		l2 = [float(k) for k in line.split()]
		l1.sort()
		l2.sort()
		#print l1, l2
		res1 = 0
		i = N-1
		j = N-1
		while(j>=0):
			if l1[i] > l2[j]:
				res1 += 1
				i -= 1
				j -= 1
			else:
				j-= 1
		res2 = 0
		i = N-1
		j = N-1
		while(i>=0):
			if l1[i]>l2[j]:
				res2 += 1
			else:
				j -= 1
			i -= 1



		
		print "Case #%i:" % (t+1), res1, res2

solve()
