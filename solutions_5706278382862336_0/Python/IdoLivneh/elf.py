import sys
import time
import itertools #use combinations!
import random

def iterate_cases_1lpc(filepath):	#1lpc = 1 line per case
	with file(filepath, 'rb') as f_in:
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			yield line_index, line.strip().split('/')

def iterate_cases_nlpc(filepath, n):	#1lpc = n line per case
	with file(filepath, 'rb') as f_in:
		case_counter = 1
		case = []
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			case.append(line.strip().split(' '))
			if not line_index % n:
				yield case_counter, case
				case_counter += 1
				case = []

def iterate_cases_glpc(filepath):		#glpc - given lines per case
	with file(filepath, 'rb') as f_in:
		case_counter = 0
		new_case = True
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			if new_case:
				new_case = False
				case_counter += 1
				case = []
				assert len(line.strip().split(' ')) == 1
				lines_left = int(line.strip())
				if not lines_left:
					new_case = True
					yield case_counter, case
				continue
			if lines_left:
				lines_left -= 1
				case.append(line.strip().split(' '))
			if not lines_left:
				new_case = True
				yield case_counter, case
			
def part_of_list_to_int(array, flags):
	assert len(array) == len(flags)
	output = []
	for index, elem in enumerate(array):
		if flags[index]:
			output.append(int(elem))
		else:
			output.append(elem)
	return output

def list_to_int(array):
	return part_of_list_to_int(array, [True] * len(array))

def part_of_list_to_float(array, flags):
	assert len(array) == len(flags)
	output = []
	for index, elem in enumerate(array):
		if flags[index]:
			output.append(float(elem))
		else:
			output.append(elem)
	return output

def list_to_float(array):
	return part_of_list_to_float(array, [True] * len(array))

def get_max_array_on_index(array, index):
	elem_len = len(array[0])
	assert index < elem_len
	for elem in array:
		assert elem_len == len(elem)
	max_sub = array[0][index]
	max_elem = array[0]
	for elem in array:
		if elem[index] > max_sub:
			max_sub = elem[index]
			max_elem = elem
	return max_elem

def list_index_in_sorted_with_position(a_list, value, pos):
	list_len = len(a_list)
	if list_len == 1:
		if a_list[0] == value:
			return pos
		return -1
	if a_list[list_len/2] > value:
		return list_index_in_sorted_with_position(a_list[:(list_len/2)], value, pos)
	else:
		return list_index_in_sorted_with_position(a_list[(list_len/2):], value, pos + (list_len/2))
	
def list_index_in_sorted_list(a_list, value):
	return list_index_in_sorted_with_position(a_list, value, 0)

def copy_list(list):
	res = []
	for elem in list:
		res.append(elem)
	return res	

############################################################
#### add solution here 									####
#### don't forget to change data from str to int/float  ####
############################################################


	
def build(strings):
	arr = []
	for s in strings:
		if not s:
			arr.append(['', []])
			continue
		last_c = ''
		str_min = ''
		nums = []
		curr_num = 1
		for c in s:
			if c != last_c:
				str_min += c
				if last_c != '':
					nums.append(curr_num)
					curr_num = 1
				last_c = c
			else:
				curr_num += 1
		nums.append(curr_num)
		arr.append([str_min, nums])
	return arr

def is_valid(arr):
	same = arr[0][0]
	for elem in arr:
		if elem[0] != same:
			return False
	return True

def get_moves(arr):
	#sum = [0.0 for _ in xrange(len(arr[0][0]))]
	#for elem in arr:
	#	for i in xrange(len(elem[0])):
	#		sum[i] += elem[1][i]
	#avg = [0 for _ in xrange(len(elem[0]))]
	#for i in xrange(len(elem[0])):
	#	avg[i] = round(sum[i]/len(arr))
	#moves = 0
	#for elem in arr:
	#	for i in xrange(len(elem[1])):
	#		moves += abs(elem[1][i] - avg[i])
	
	str_len = len(arr[0][0])
	med = []
	for i in xrange(str_len):
		tmparr = []
		for elem in arr:
			tmparr.append(elem[1][i])
		tmparr.sort()
		med.append(tmparr[(len(arr)-1) // 2])
	
	#print arr
	#print med
	
	moves = 0
	for elem in arr:
		for i in xrange(str_len):
			moves += abs(med[i] - elem[1][i])
		
			
	#print '\t',avg
	#print '\t', moves
	
	return int(moves)

def gcd(a, b):
    """Calculate the Greatest Common Divisor of a and b.

    Unless b==0, the result will have the same sign as b (so that when
    b is divided by it, the result comes out positive).
    """
    while b:
        a, b = b, a%b
    return a
	
def solve(p, q):
	g = gcd(p,q)
	p = p / g
	q = q / g
	print p, q
	
	flag = False
	for i in xrange(41):
		if q == 2**i:
			flag = True
			break
	if not flag: return 'impossible'
	
	for j in xrange(41):
		if 2**j > p:
			break
	
	return i - (j-1)
	
def calc_result(case):
	result = None
	p, q = list_to_int(case)
	print p,q
	
	
	result = solve(p, q)
	
	
	return result

def main(filepath):
	start_time = time.time()
	with file('output.txt', 'wb') as f_out:
		
		######################################
		#### select input iteration type: ####
		####	- iterate_cases_1lpc	  ####
		####	- iterate_cases_nlpc +n	  ####
		####	- iterate_cases_glpc	  ####
		######################################
		for case_index, case in iterate_cases_1lpc(filepath):
			
			print "case #%d: time:%.02f" % (case_index, time.time() - start_time)
			result = calc_result(case)
			
			#######################
			#### format output ####
			#######################
			f_out.write("Case #%d: %s\n" % (case_index, result))
				
if __name__ == '__main__':
	main(sys.argv[1])
