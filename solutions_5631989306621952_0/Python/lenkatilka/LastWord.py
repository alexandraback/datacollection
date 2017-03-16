
def main():

	import sys
	filename = sys.argv[1]

	with open(filename) as f:
		content = f.readlines()
	outputFile = open("outputLatest.out", 'w')
	

	T = int(content[0])

	for test in range(T):

		index = 1 + test
		string = content[index]
		latest = findLatest(string)

		
		outputStr = "Case #" + str(test+1) + ": "

		outputStr += latest

		outputFile.write(outputStr)

def findLatest(string):

	if not string: return string

	latest = string[0]

	for chInd in range(1, len(string)):
		if string[chInd] >= latest[0]:
			latest = string[chInd] + latest
		else:
			latest = latest + string[chInd]
	return(latest)

if __name__ == '__main__':
	main()
