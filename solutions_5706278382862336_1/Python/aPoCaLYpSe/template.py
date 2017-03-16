import sys, os, math
inpath = sys.argv[1]

def parseCase(instrm):
	args = instrm.readline().strip().split("/")
	return (int(args[0]), int(args[1]))


def factor(D):
	#print("@factor: " + str(D))
	exp = 0
	while (D > 1):
		if (D % 2 != 0):
			break
		D = D/2
		exp += 1
	
	#print("@result: " + str(D) + ", " + str(exp))
	return (D, exp)

def solveCase(case):
	(N,D) = case
	(A,E) = factor(N)
	(B,F) = factor(D)
	if (A % B != 0):
		return "impossible"
	"""
	print("B: " + str(B))
	print("A: " + str(A))
	print("B/A: " + str(B/A))
	print("math.log(B/float(A),2): " + str(math.log(B/float(A),2)))
	print("math.floor(math.log(B/float(A),2))"+str(math.floor(math.log(B/float(A),2))))
	"""
	#print("math.log(B/float(A),2): " + str(math.log(B/float(A),2)))
	res = F-E + int(math.ceil(math.log(B/float(A), 2)))
	return res


if __name__=="__main__":
	instrm = open(inpath, 'r')
	cases = int(instrm.readline().strip())
	for i in range(cases):
		case = parseCase(instrm)
		res = solveCase(case)
		print("Case #" + str(i+1) + ": " + str(res))
	instrm.close()
