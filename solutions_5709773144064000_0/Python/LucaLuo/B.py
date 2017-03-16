import math

def cookies(C, F, X, sec, prod):
	secWait = X / prod
	secBuy = C / prod + X / (prod + F)
	while secWait > secBuy:
		sec += C / prod
		prod += F
		secWait = X / prod
		secBuy = C / prod + X / (prod + F)
	return sec + secWait
	
# inFile = open("input.txt", "r")
inFile = open("B-small-attempt0.in", "r")
outFile = open("B.out", "w")
T = int(inFile.readline())

for i in range(T):
	C, F, X = inFile.readline().split()
	outFile.write( ("Case #%d: " % (i + 1)) 
					+ str( cookies( float(C), float(F), float(X), float(0.0), float(2.0) ) )
					+ '\n'
				)
	





# for line in File:
# 	f.append(line.split())
# for i in range(int(f[0][0])):
# 	name = f[i+1][0]
# 	n = int(f[i+1][1])
# 	print "Case #%d:" %(i+1), solve(name, n)