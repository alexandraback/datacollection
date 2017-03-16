import sys

def map(func, l):
	return [func(i) for i in l]


def parseCase(instrm):
	return map(float, instrm.readline().strip().split(" "))

def solveCase(input):
	C = input[0]; F = input[1]; X = input[2]
	T = 0; n = 0
	ans = None
	#upon entrance T is the cost of buying n farms
	while (True):
		newT = T + C/(2 + n*F) #cost of n+1 farms
		if (T + X/(2 + n*F)) < (newT + X/(2 + (n+1)*F)):
			ans = T + X/(2 + n*F); break
		T = newT
		n += 1
	return ans



if __name__=="__main__":
	instrm = open(sys.argv[1])
	cases = int(instrm.readline().strip())
	for i in range(cases):
		input = parseCase(instrm)
		print("Case #" + str(i+1) +": "+str(solveCase(input)))
	instrm.close()