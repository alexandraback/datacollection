f = open("B-large.in", "r")
new_file = open("rankAndFileLargeOut", "w")
t = int(f.readline())

def solver(all_but_one_list):
	numbers_count = {}
	for row_or_col in all_but_one_list:
		for j in row_or_col:
			if j in numbers_count:
				numbers_count[j] += 1
			else:
				numbers_count[j] = 1
	result = []
	for number in numbers_count.keys():
		if numbers_count[number] % 2 == 1:
			result.append(number)
	result.sort()
	return " ".join([str(x) for x in result])

for i in range(1,t+1):
	n = int(f.readline())
	all_but_one_list = []
	for j in xrange(2*n-1):
		line = f.readline()[:-1]
		one_list = [int(x) for x in line.split(" ")]
		all_but_one_list.append(one_list)
	result = solver(all_but_one_list)
	new_file.write("Case #"+str(i)+ ": "+result+"\n")
