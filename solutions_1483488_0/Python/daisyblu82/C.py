import sys

def recycled(A,B):
	y = 0
	for n in xrange(A,B):
		N = str(n)
		M = ''
		Ms = []
		for i in xrange(len(N)):
			M = N[i:]+N[0:i]
			if int(N) < int(M) and A <= int(M) and int(M) <= B and M not in Ms:
				y += 1
				Ms.append(M)
	return y

if __name__=='__main__':
	f = open(sys.argv[1], 'r')
	T = int(f.readline()[:-1])
	for case_no in range(1, T + 1):
		A,B = map(int, f.readline()[:-1].split(' '))
		y = recycled(A,B)	
		print "Case #%s: %s" % (case_no, y)
	
