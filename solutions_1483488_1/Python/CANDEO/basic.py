import sys

input_list = []
output_list = []

try:
	input_filename = sys.argv[1]
	output_filename = input_filename[:sys.argv[1].find('.')]+'.out'
except:
	print 'input filename as argv'
	exit()

try:
	input_f = open("./"+input_filename)
	input_lines = input_f.readlines()
	input_count = 0
	for input_line in input_lines:
		input_split = input_line.split()
		input_list.append(input_split)
	input_f.close()
except:
	print 'read error'
	exit()

input_list.pop(0)

def getList(I):
	S = str(I)
	dummyList = []
	for x in range(len(S)):
		dummyList.append(int(S[x:]+S[:x]))
	dummyList = list(set(dummyList))
	dummyList.sort()
	return dummyList

for input_line in input_list:
	m = int(input_line[0])
	M = int(input_line[1])

	dummyCount2 = 0

	for x in range(m, M+1):
		dummyList = getList(x)
		dummyCount = 0
		for y  in range(len(dummyList)):
			if dummyList[y] > M or dummyList[y] < m or dummyList[y] <= x:
				continue
			dummyCount = dummyCount + 1
		dummyCount2 = dummyCount2 + dummyCount

	result = dummyCount2
	output_list.append([result])

try:
	output_f = open("./"+output_filename, "w")
	output_f.close()
except:
	pass

try:
	output_f = open("./"+output_filename, "a")
	output_str = ''

	for x in range(len(output_list)):
		output_f.write('Case #' + str(x+1)+': '+str(output_list[x][0])+"\n")
		print x
	output_f.close()
except:
	print 'write error'
	exit()
