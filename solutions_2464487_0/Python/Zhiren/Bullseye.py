import sys

def main(filename):
	result = ''
	file = open(filename)
	numberOfTests = int(file.readline())
	for i in range(numberOfTests):
		nm = [int(num) for num in file.readline().split()]
		r = nm[0]
		t = nm[1]
		solution = solveBullseye(r,t)
		print i+1
		result += 'Case #%d: %s\n' % (i+1,solution)
	file.close()
	return result
	
def solveBullseye(r, t):
	return getResult(1, 100000000000000000000, r, t)

def getResult(low, high, r, paint):
	mid = 0
	lastIter = 0
	while low<high:
		mid = (low+high)//2
		midval = mid*2*r + 2*mid*(mid-1) + mid
		if midval<paint:
			if low == lastIter:
				return mid
			lastIter = low
			low = mid
		elif midval>paint:
			high = mid
		else:
			return mid
	return max(1, mid-1)
		
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