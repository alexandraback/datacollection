def solveB():
	fileIn = open("in.txt", "r")
	lines = [line.strip() for line in fileIn]
	fileIn.close()
	
	fileOut = open("out.txt", "w")
	
	
	T = int(lines[0])
	c = 0
	i = 1
	while c < T:
		[A, B, K] = [int(x) for x in lines[i].split(" ")]
		
		i += 1
		c += 1
		result = "Case #%i: %s\n" % (c, solve(A, B, K))
		print result
		fileOut.write(result)
	
	fileOut.close()
		
def solve(A, B, K):
	solution = 0
	for a in range(A):
		for b in range(B):
			if (a & b) < K:
				solution += 1
	return solution

solveB()