import sys, math

def map(func, l):
	return [func(i) for i in l]


def parseCase(instrm):
	return map(int, instrm.readline().strip().split(" "))

def writeSolution(R, C, i, j, r):
	#sprint((R, C, i, j, r))
	lines = []
	for a in range(r):
		lines.append(["."]*(j+1) + ["*"]*(C-j-1))
	for a in range(i-r):
		lines.append(["."]*j + ["*"]*(C-j))
	for a in range(R-i):
		lines.append(["*"]*C)
	
	lines[0][0] = "c"
	if (r==1):
		if (lines[i-1][j-1] != "."):
			raise Exception
		lines[i-1][j-1] = "*"
		if (lines[1][j] != "*"):
			raise Exception
		lines[1][j] = "."
		
	return "\n".join("".join(l) for l in lines)
	

def solveCase(input):
	R = input[0]; C = input[1]; M = input[2]
	N = R*C - M
	if (M == 0):
		return writeSolution(R, C, R, C, 0)
	if (N == 1):
		return writeSolution(R, C, 1, 1, 0)
	if (R == 1 or C == 1):
		return writeSolution(R, C, min(R,N), min(C,N), 0)
		
	maxI = min(R, int(N/2))
	minI = max(2, math.ceil(N/C))
	for i in range(minI,(maxI+1)):
		j = int(N/i)
		r = N % i
		if (r >= 2 or r == 0):
			return writeSolution(R, C, i, j, r)
		
		if (r == 1 and i > 2 and j > 2):
		#here you can put the element (i,j) right after the singleton in the last column
			return writeSolution(R, C, i, j, r)
	return "Impossible"


if __name__=="__main__":
	instrm = open(sys.argv[1])
	cases = int(instrm.readline().strip())
	for c in range(cases):
		input = parseCase(instrm)
		res = str(solveCase(input))
		if (False):#res=="Impossible"
			R = input[0]; C = input[1]; M = input[2]
			N = R*C - M
			sol = ["c"] + ["."]*(N-1) + ["*"]*M
			solstring = ""
			for i in range(R):
				solstring += "".join(sol[:C]) + "\n"
				sol = sol[C:]
			print("Case #" + str(c+1) +":\n"+str(input) + "\n" + str((R,C,M,N))+"\n"+solstring)
		print("Case #" + str(c+1) +":\n"+res)
	instrm.close()