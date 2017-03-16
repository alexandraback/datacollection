import sys

def main(filename):
	result = ''
	file = open(filename)
	numberOfTests = int(file.readline())
	for i in range(numberOfTests):
		an = [int(num) for num in file.readline().split()]
		a = an[0]
		n = an[1]
		motes = [int(num) for num in file.readline().split()]
		result += 'Case #%d: %s\n' % (i+1,solveOsmos(a, motes))
	file.close()
	return result
	
def solveOsmos(a, motes):
	motesSorted = sorted(motes)
	moves = 0
	posibleSolutions = []
	while len(motesSorted) > 0:
		posibleSolutions.sort()
		if len(posibleSolutions) > 0 and moves >= posibleSolutions[0]:
			return posibleSolutions[0]
		if a>motesSorted[0]:
			a += motesSorted.pop(0)
		else:
			if len(motesSorted) == 1:
				moves += 1
				break
			if 2*a - 1 <= motesSorted[0]:
				posibleSolutions.append(moves+len(motesSorted))
			if a == 1:
				posibleSolutions.sort()
				return posibleSolutions[0]
			motesSorted.insert(0, a-1)
			moves += 1
	posibleSolutions.append(moves)
	posibleSolutions.sort()
	return posibleSolutions[0]
		
if __name__ == '__main__':
	if len(sys.argv) < 3:
		print 'Not enough files specified'
		sys.exit(1)
	inputfilename = sys.argv[1]
	outputfilename = sys.argv[2]
	result = main(inputfilename)
	outputfile = open(outputfilename, 'w')
	outputfile.write(result)
	outputfile.close()
	print result