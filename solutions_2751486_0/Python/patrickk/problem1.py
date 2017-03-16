import math
f = open("in.txt")
T = int(f.readline())

w = open("out.txt", "w")

def isGood(sub):
	for c in sub:
		if c in "aeiou":
			return False
	return True

def solveTestcase():
	global i
	inp = f.readline().split()
	name = inp[0]
	n = int(inp[1])

	positions = set([])

	for j in range(len(name) - n + 1):
		sub = name[j:j+n]
		if isGood(sub):
			for k in range(j + 1):
				for l in range(j + n - 1, len(name)):
					positions.add((k,l))
	w.write("Case #" + str(i + 1) + ": " + str(len(positions)) + "\n")
	return None

for i in range(T):
	solveTestcase()