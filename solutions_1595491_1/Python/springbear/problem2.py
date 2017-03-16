f = open("B-large.in")
num_testcases = int(f.readline())
inputs = []

for i in range(0, num_testcases):
	input = f.readline()
	inputs.append(input)

for i in range(0, num_testcases):
	inputs[i] = inputs[i].split()
	num_googlers = int(inputs[i][0])
	num_surprising = int(inputs[i][1])
	p = int(inputs[i][2])

	count = 0
	scores = []
	for j in range(0, num_googlers):
		scores.append(int(inputs[i][j+3]))

	scores.sort(reverse=True)

	for j in range(0, num_googlers):
		if ((p - 1) * 2 + p) > scores[j] and (p - 1) >= 0:
			if num_surprising > 0:
				num_surprising = num_surprising - 1
				if (p + (p-2)*2) <= scores[j] and (p - 2) >= 0:
					count = count + 1
		else : 
			count = count + 1

	print "Case #%d:" % (i+1),
	print count
