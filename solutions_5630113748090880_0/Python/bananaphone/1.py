T = int(raw_input())

def doprob():
	D = {}
	N = int(raw_input())
	for i in xrange(2*N -1):
		xx = raw_input()
		yy = xx.split()
		for ii in yy:
			if ii in D:
				D[ii] += 1
			else:
				D[ii] = 1
	out  = []
	for i in D.keys():
		if D[i] %2 != 0:
			out.append(int(i))
	out.sort()
	nnn = ""
	for i in out:
		nnn += str(i) + " " 
	return nnn[:-1]

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())