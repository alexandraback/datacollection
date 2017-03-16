import sys

filename = "B-small-attempt0"

def solve_case(A, B, K):
	count = 0
	for a in range(A):
		for b in range(B):
			if a & b < K:
				count += 1
	return count

def readInt(inFile):
	return int(inFile.readline())

def readFloats(inFile):
	return [float(n) for n in inFile.readline().split(" ")]

def readInts(inFile):
	return [int(n) for n in inFile.readline().split(" ")]

with open(filename + ".in", 'r') as inFile:
	output_data = []

	# parse input
	T = readInt(inFile)
	for t in range(T):
		[A, B, K] = readInts(inFile)
		pairs = solve_case(A, B, K)
		output_data.append("Case #%s: %s" % (t+1, pairs))

	if len(output_data) > 0:
		with open(filename + ".out", 'w') as outFile:
			outFile.write("\n".join(output_data))
	else:
		print("no output")




