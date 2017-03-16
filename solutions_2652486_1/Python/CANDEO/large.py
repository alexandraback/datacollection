import sys

input_list = []
output_list = []

# for small input
N = 12

def factorize_small(num):
	result = [0, 0, 0, 0]#each 2, 3, 5, 7
	num2 = num
	if num == 1:
		return result[:]
	while num2 > 1:
		if num2 % 2 == 0:
			result[0] += 1
			num2 = num2 / 2
		elif num2 % 3 == 0:
			result[1] += 1
			num2 = num2 / 3
		elif num2 % 5 == 0:
			result[2] += 1
			num2 = num2 % 5
		elif num2 % 7 == 0:
			result[3] += 1
			num2 = num2 % 7
		else:
			print 'error', num, num2, result
	return result[:]

def max_5_7(factorize_list):
	max_3 = 0
	max_5 = 0
	max_7 = 0
	for x in range(len(factorize_list)):
		factorize_item = factorize_list[x]
		if max_3 < factorize_item[1]:
			max_3 = factorize_item[1]
		if max_5 < factorize_item[2]:
			max_5 = factorize_item[2]
		if max_7 < factorize_item[3]:
			max_5 = factorize_item[3]
	return max_5, max_7

def get_result(factorize_list, max_5, max_7):
	global N
	avail_card_num = N - max_5 - max_7
	if avail_card_num == 0:
		return '5'*max_5 + '7'*max_7
	min2 = 0
	min3 = 0
	min8 = 0
	for x in range(len(factorize_list)):
		factorize_item = factorize_list[x]
		if factorize_item[0] == 1 and factorize_item[1] == 0:
			min2 = 1
		elif factorize_item[0] == 0 and factorize_item[1] > 0:
			min3 = factorize_item[1]
		elif factorize_item[0] == avail_card_num * 3:
			return '5'*max_5 + '7'*max_7 + '8' * avail_card_num
	return get_result_real(factorize_list, min2, min3, max_5, max_7)

def get_result_real(factorize_list, min2, min3, max_5, max_7):
	global N
	avail_card_num = N - min2 - min3 - max_5 - max_7
	return '2'*min2 + '3'* min3 + '5'*max_5 + '7'*max_7 + '246824682468'[0:avail_card_num]

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
RNMK = input_list.pop(0)
R = int(RNMK[0])
#N = int(RNMK[1])
M = int(RNMK[2])
K = int(RNMK[3])
#print input_list

for input_line in input_list:

	# do some works here
	factorize_list = []
	for x in range(len(input_line)):
		input_item = int(input_line[x])
		factorize_list.append(factorize_small(input_item))
	max_5, max_7 = max_5_7(factorize_list)
	result = get_result(factorize_list, max_5, max_7)
	output_list.append([result])

try:
	output_f = open("./"+output_filename, "w")
	output_f.close()
except:
	pass

try:
	output_f = open("./"+output_filename, "a")
	output_str = ''

	output_f.write('Case #1:\n')
	for x in range(len(output_list)):
		output_f.write(str(output_list[x][0])+"\n")
		print x
	output_f.close()
except:
	print 'write error'
	exit()
