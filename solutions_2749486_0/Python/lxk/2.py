fin = open('input.txt')
lines = fin.read().split("\n")

countTests = int(lines[0])

for testCase in range(1, countTests + 1):
	l = lines[testCase].split()

	x = int(l[0])
	y = int(l[1])

	path = ""

	if x > 0:
		path += 'WE' * x
	elif x < 0:
		path += 'EW' * (-x)

	if y > 0:
		path += 'SN' * y
	elif y < 0:
		path += 'NS' * (-y)

	print "Case #" + str(testCase) + ": " + path