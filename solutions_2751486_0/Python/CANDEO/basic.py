import sys

input_list = []
output_list = []

def transform(input_list):
	output_list = []
	vowels = ['a', 'e', 'i', 'o', 'u']
	for x in range(len(input_list)):
		input_item = input_list[x]
		if input_item in vowels:
			output_list.append(0)
		else:
			output_list.append(1)
	return output_list[:]

# for one case
def get_result(transform_list, n):
#	print transform_list, n
	n = int(n)
	result_count = 0
	for x in range(len(transform_list)):#x = begin point
		for y in range(x+n, len(transform_list)+1):#y = end point
			sub_list = transform_list[x:y]
#			print 'sub', sub_list
			if check_list(sub_list, n) == True:
				result_count += 1
	return result_count

def check_list(sub_list, n):
#	print sub_list, n, 'check'
	cont_count = 0
	result = False
	for x in range(len(sub_list)):
		if sub_list[x] == 1:
			cont_count += 1
			if cont_count == n:
				result = True
				break
		else:
			cont_count = 0
#	print result
	return result

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

for input_line in input_list:
	# do some works here
#	print input_list
	result = get_result(transform(input_line[0]), input_line[1])
	output_list.append([result])
	print

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
