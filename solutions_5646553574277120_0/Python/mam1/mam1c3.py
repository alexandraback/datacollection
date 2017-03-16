#MAM, Google Code Jam - Round 1C, Problem 3
#Very naive solution that will only work for small case with C = 1

import itertools

def combos(needed, vals, V):
	possibles = set()
	for x in xrange(1, V+1):
		for s in itertools.combinations(vals, x):
			possibles.add(sum(s))

	for each in possibles:
		needed.discard(each)

def findSolution(numVals, valsToTry, vals, needed):

	for s in itertools.combinations(valsToTry, numVals):
		temp = set()
		temp.update(s)
		temp.update(vals)

		myNeeded = set()
		myNeeded.update(needed)

		combos(myNeeded, temp, len(temp))
		if not myNeeded:
			return True
	return False


def solve(c, vals):
	C, D, V = [int(x) for x in c.split()]

	vals = [int(x) for x in vals.split()]

	needed = set(xrange(1, V+1))
	combos(needed, vals, V)
	#needed is now the values that need to be provided for

	maxiters = len(needed)
	if maxiters < 2: return maxiters
	#if no return, 2 or more numbers not accounted for


	maxV = max(needed)



	valsToTry = set(xrange(1, maxV+1))
	for each in vals:
		valsToTry.discard(each)

	answer = 0

	for x in xrange(1, maxiters):
		if findSolution(x, valsToTry, vals, needed):
			return x
	
	return maxiters

def main():
	with open('C-small-attempt0.in', 'r') as infile, open('output.txt', 'w') as outfile:
		
		T = int(infile.readline())
		for x in xrange(T):
			line = infile.readline().rstrip()
			vals = infile.readline().rstrip()
			outfile.write("Case #" + str(x + 1) + ": " + str(solve(line, vals)) + "\n")

if __name__ == "__main__":
	main()