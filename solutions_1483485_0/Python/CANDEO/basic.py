import sys

input_list = []
input_list2 = []
input_list3 = []
output_list = []

try:
	input_filename = sys.argv[1]
	input_filename2 = sys.argv[2]
	input_filename3 = sys.argv[3]
	output_filename = input_filename[:sys.argv[1].find('.')]+'.out'
except:
	print 'input filename as argv'
	exit()

try:
	input_f = open("./"+input_filename)
	input_lines = input_f.readlines()
	input_count = 0
	for input_line in input_lines:
		input_split = input_line
		input_list.append(input_split)
	input_f.close()

	input_f2 = open("./"+input_filename2)
	input_lines2 = input_f2.readlines()
	input_count2 = 0
	for input_line2 in input_lines2:
		input_split2 = input_line2
		input_list2.append(input_split2)
	input_f2.close()

	input_f3 = open("./"+input_filename3)
	input_lines3 = input_f3.readlines()
	input_count3 = 0
	for input_line3 in input_lines3:
		input_split3 = input_line3
		input_list3.append(input_split3)
	input_f3.close()
except:
	print 'read error'
	exit()

input_list.pop(0)
input_list2.pop(0)
input_list3.pop(0)

googleList = {}

for x in range(len(input_list)):
	input_line = input_list[x]

	for y in range(len(input_line)):
		input_letter = input_line[y]
		googleList[input_letter] = input_list2[x][y]

	# do some works here
googleList['q'] = 'z'
googleList['z'] = 'q'

for input_line in input_list3:
	new_line = ''

	for x in range(len(input_line)-1):
		new_line = new_line + googleList[input_line[x]]

	# do some works here
	
	output_list.append([new_line])

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


