fin = open('input.txt')
lines = fin.read().split("\n")

testsCount = int(lines[0])
for testCase in range(1, testsCount + 1):
	(a, b, k) = [int(x) for x in lines[testCase].split()]

	winCount = 0
	for i in range(0, a):
		for j in range(0, b):
			if i & j < k:
				winCount += 1

	print "Case #" + str(testCase) + ":", winCount