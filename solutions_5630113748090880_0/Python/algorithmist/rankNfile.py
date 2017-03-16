
def getMissingList(heights):
	heights.sort()
	missingNumbers = []
	index = 0
	while index < len(heights):
		if index == len(heights) - 1:
			missingNumbers.append(heights[index])
			break
		else:
			if(heights[index] == heights[index + 1]):
				index += 2
			else:
				missingNumbers.append(heights[index])
				index += 1
	return missingNumbers


def main():
	inputFile = open('B-small-attempt0.in', 'r')
	outputFile = open('rf.txt', 'w')
	cases = int(inputFile.readline().strip())
	for i in range(cases):
		N = int(inputFile.readline().strip())
		allHeights = []
		for j in range(2 * N - 1):
			allHeights += [int(x) for x in inputFile.readline().strip().split()]
		missingList = getMissingList(allHeights)
		val = ' '.join([str(x) for x in missingList])
		outputFile.write('Case #' + str(i + 1) + ': ' + val + '\n')


main()

