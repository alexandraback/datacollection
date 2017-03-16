import sys

#Dp = [0]*101

T = int(sys.stdin.readline().strip())

for i in range(T):
	A, B = [int(x) for x in sys.stdin.readline().split()]
	P = [float(x) for x in sys.stdin.readline().split()]
	
	correct = 1.0
	expect = []
	err = []
	for k in range(len(P)):
		correct *= P[k]
		err.append(1-correct)	
	err.reverse()
	for k, e in enumerate(err):
		expect.append(B-A+2*k+1+e*(B+1))
	dall = A+B+1
	giveup = 1+B+1
	expect.append(float(dall))
	expect.append(float(giveup))

	print "Case #%d: %f"%(i+1, min(expect))
