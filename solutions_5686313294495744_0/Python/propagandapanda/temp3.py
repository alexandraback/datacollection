array = []
with open("C-small-attempt1.in", "r") as ins:
	for line in ins:
		array.append(line.strip('\n\r'))
array2 = []
index = 1
while index < len(array):
	num = int(array[index])
	temp = []
	for i in range(1, num + 1):
		temp.append(array[index + i].split())
	index += num + 1
	array2.append(temp)

for b in range(0, len(array2)):
	i = array2[b]
	set1 = {}
	set2 = {}
	fakes = 0
	for z in i:
		if z[0] in set1:
			set1[z[0]] = set1[z[0]] + 1
		else:
			set1[z[0]] = 1
		if z[1] in set2:
			set2[z[1]] = set2[z[1]] + 1
		else:
			set2[z[1]] = 1
	for z in i:
		if set1[z[0]] > 1 and set2[z[1]] > 1:
			fakes += 1
			set1[z[0]] = set1[z[0]] - 1
			set2[z[1]] = set2[z[1]] - 1
	print("Case #" + str((b + 1)) + ": " + str(fakes))

