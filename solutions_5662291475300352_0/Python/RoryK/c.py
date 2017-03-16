def formatLine(line):
	s = line.split()
	s = [int(i) for i in s]

	return s

def solveTestCase(line):
	line = formatLine(line)





########
data = open("testfile.txt", 'r')
out = open("answer.txt", "w")
numberCases = int(data.readline())
#########

for i in range(numberCases):

	n= int(data.readline())
	passed = 0

	if n == 1:
		passed = 0
		a = data.readline()
	else:

		hikers = {(0,0),(0,0)}
		count = 0
		for j in range(n):
			(d,h,m) = formatLine(data.readline())
			if count == 0:
				hiker0 = (d,m)
				count += 1
			else:
				hiker1 = (d,m)

			if h == 2:
				hiker1 = (d,m+1)

		a = (360-hiker0[0]) * hiker0[1]
		b = (360-hiker1[0]) * hiker1[1]

		if a < b:
			a = hiker0
			hiker0 = hiker1
			hiker1 = a

		timetoStart0 = (360-hiker0[0]) * hiker0[1]
		timetoStart1 = (360-hiker1[0]) * hiker1[1]

		speedDiff = (1.0 * hiker0[1])/hiker0[1]



		if ((360+360-hiker1[0]) * hiker1[1]) <= ((360-hiker0[0]) * hiker0[1]):
			passed = 1



	s = "Case #{0:d}: {1:d}\n".format(i+1, passed)
	print s
	out.write(s)