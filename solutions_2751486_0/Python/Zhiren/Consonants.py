import sys

def main(filename):
	result = ''
	file = open(filename)
	numberOfTests = int(file.readline())
	for i in range(numberOfTests):
		nm = file.readline().split()
		text = nm[0]
		n = int(nm[1])
		result += 'Case #%d: %s\n' % (i+1,solveConsonants(text, n))
	file.close()
	return result
	
def solveConsonants(text, n):
	count = 0
	for i in range(len(text)):
		for j in range(i+1, len(text)+1):
			if numberOfConsecutiveConsonants(text[i:j]) >= n:
				count += 1
	return count
	
def numberOfConsecutiveConsonants(text):
	count = 0
	max = 0
	for r in range(len(text)):
		if isConsonant(text[r]):
			count += 1
		else:
			if count>max:
				max = count
			count = 0
	if count>max:
		max = count
	return max
		
def isConsonant(letter):
	return letter not in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
		
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