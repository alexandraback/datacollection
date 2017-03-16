import math
array = []
with open("B-small-attempt2.in", "r") as ins:
	for line in ins:
		array.append(line.strip('\n\r'))

for i in range(1, len(array)):
	temp = array[i].split()
	word1 = temp[0]
	len1 = len(word1)
	word2 = temp[1]
	len2 = len(word2)
	list1 = []
	list2 = []
	num1 = 0
	num2 = 0
	for d in range(0, len(word1)):
		c = word1[d]
		if c == "?":
			list1.insert(0, len1 - d - 1)
		else:
			num1 += int(c) * int(math.pow(10, len1 - 1 - d))

	for d in range(0, len(word2)):
		c = word2[d]
		if c == "?":
			list2.insert(0, len2 - d - 1)
		else:
			num2 += int(c) * int(math.pow(10, len2 - 1 - d))

	total1 = []
	total1.append(num1)
	for d in list1:
		temp = []
		for z in range(0, 10):
			for t in total1:
				temp.append(t + z * int(math.pow(10, d)))
		total1 = temp

	total2 = []
	total2.append(num2)
	for d in list2:
		temp = []
		for z in range(0, 10):
			for t in total2:
				temp.append(t + z * int(math.pow(10, d)))
		total2 = temp

	real1 = 0
	real2 = 0
	dif = 1000000000
	for a in total1:
		for b in total2:
			if abs(a - b) < dif:
				real1 = a
				real2 = b
				dif = abs(a - b)
	print("Case #" + str(i) + ": " + str(real1).zfill(len1) + " " + str(real2).zfill(len2))





