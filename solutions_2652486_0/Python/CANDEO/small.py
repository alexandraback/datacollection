import sys

input_list = []
output_list = []

# for small input
N = 3

def factorize_small(num):
	result = [0, 0, 0]#each 2, 3, 5
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
		else:
			print 'error', num, num2, result
	return result[:]

def max_3_5(factorize_list):
	max_3 = 0
	max_5 = 0
	for x in range(len(factorize_list)):
		factorize_item = factorize_list[x]
		if max_3 < factorize_item[1]:
			max_3 = factorize_item[1]
		if max_5 < factorize_item[2]:
			max_5 = factorize_item[2]
	return (max_3, max_5)

def get_result(factorize_list, max_3, max_5):
	global N
	avail_card_num = N - max_3 - max_5
	if avail_card_num == 0:
		return '3'*max_3 + '5'*max_5
	elif avail_card_num == 1:
		for x in range(len(factorize_list)):
			factorize_item = factorize_list[x]
			if factorize_item[0] == 1:
				return '2' + '3'*max_3 + '5'*max_5
			elif factorize_item[0] == 2:
				return '3'*max_3 + '4' + '5'*max_5
		return '2' + '3'*max_3 + '5'*max_5		
	elif avail_card_num == 2:
		for x in range(len(factorize_list)):
			factorize_item = factorize_list[x]
			if factorize_item[0] == 4:
				return '3'*max_3 + '44' + '5'*max_5
			elif factorize_item[0] == 3:
				return '2' + '3'*max_3 + '4' + '5'*max_5
		return '2' + '3'*max_3 +'4'+ '5'*max_5		
	elif avail_card_num == 3:
		for x in range(len(factorize_list)):
			factorize_item = factorize_list[x]
			min_2 = 0
			min_4 = 0
			if factorize_item[0] == 6:
				return '3'*max_3 + '444' + '5'*max_5
			elif factorize_item[0] == 1:
				min_2 = 1
			elif factorize_item[0] == 3:
				min_2 = 1
				min_4 = 1
		if min_2 == 0 and min_4 == 0:
			return '224'
		elif min_2 == 0 and min_4 == 1:
			return '224'
		elif min_2 == 1 and min_4 == 0:
			return '222'
		elif min_2 == 1 and min_4 == 1:
			return '224'
		else:
			return '224'	

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
	max_3, max_5 = max_3_5(factorize_list)
	result = get_result(factorize_list, max_3, max_5)
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
