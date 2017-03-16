import sys

def main(filename):
	result = ''
	file = open(filename)
	numberOfTests = int(file.readline())
	for i in range(numberOfTests):
		nm = [int(num) for num in file.readline().split()]
		e = nm[0]
		r = nm[1]
		n = nm[2]
		values = [int(num) for num in file.readline().split()]
		solution = solveEnergy(e,r,n,values)
		print i+1
		result += 'Case #%d: %s\n' % (i+1,solution)
	file.close()
	return result
	
def solveEnergy(e,r,n,values):
	sols = []
	for i in range(n):
		sol = []
		for j in range(e+1):
			if i > 0:
				maxVal = 0
				for k in range(j+1):
					currentE = min(e, j-k+r)
					value = k*values[n-i-1] + sols[i-1][currentE]
					if value > maxVal:
						maxVal = value
				sol.append(maxVal)
			else:
				sol.append(j*values[n-1])
		sols.append(sol)
	maxE = 0
	for i in range(e+1):
		if sols[n-1][i] > maxE:
			maxE = sols[n-1][i]
	return maxE
		
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