import sys

def main():
	testCases = int(raw_input())
	#print testCases
	testCount = 1
	while (testCount <= testCases):
		testCase = []
		line = raw_input().split(" ")
		#print line
		inital_size = int(line[0])
		mote_count = int(line[1])

		motes = [int(x) for x in raw_input().split(" ")]

		result = handleTest(inital_size, motes)

		print "Case #%d: %d" % (testCount, result)

		testCount += 1

	return 0

def handleTest(size, motes):
	motes.sort()

	count = 0
	index = 0
	for i in xrange(len(motes)):
		if (motes[i] >= size):
			break

		size += motes[i]
		index += 1

	if (index == len(motes)):
		return count
	if (size == 1):
		return len(motes) - index

	firstCount = 1 + handleTest(size + size - 1, motes[index:])
	if (firstCount > len(motes) - index):
		return len(motes) - index
	return firstCount 

if __name__ == "__main__":
	main()
