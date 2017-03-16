import sys
import time
import itertools #use combinations!
import random
import math

def iterate_cases_1lpc(filepath):	#1lpc = 1 line per case
	with file(filepath, 'rb') as f_in:
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			yield line_index, line.strip().split(' ')

def iterate_cases_nlpc(filepath, n):	#nlpc = n line per case
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

def count_hikers(groups):
	count = 0
	for g in groups:
		count += g[1]
	return count

def solve(groups):
	if count_hikers(groups) <= 1:
		return 0
	
	hikers = []
	for g in groups:
		for i in xrange(g[1]):
			h = [g[0], g[2] + i]
			if h not in hikers:
				hikers.append(h)
	
	M = hikers[0][1]
	found_flag = False
	for h in hikers:
		if h[1] != M:
			found_flag = True
			break
	if not found_flag:
		return 0
	
	print hikers
	
	
	if hikers[0][0] < hikers[1][0]:
		first  = hikers[0]
		second = hikers[1]
	else:
		first  = hikers[1]
		second = hikers[0]
	
	if hikers[0][1] < hikers[1][1]:
		fast = hikers[0]
		slow = hikers[1]
	else:
		fast = hikers[1]
		slow = hikers[0]
	
	s_slow = 360.0/slow[1]
	s_fast = 360.0/fast[1]
	d_slow = slow[0]
	d_fast = fast[0]
	
	L = 360.0
	
	if d_fast > d_slow:
		target = 1
	else:
		target = 2
	
	time_for_slow = (360.0 - slow[0])/s_slow
	
	ts = []
	for i in xrange(3):
		ts.append((L - d_fast + i*L) / s_fast)
	print ts
	print time_for_slow
	
	count = 0
	for t in ts:
		if t < time_for_slow:
			count += 1
	print count		
	
	if count >= target:
		return 1
	return 0
	
	
	
	
	
	
def calc_result(case):
	result = None
	groups = []
	for row in case:
		groups.append(list_to_int(row))
	print groups
	
	result = solve(groups)
	
	print result
	
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
		for case_index, case in iterate_cases_glpc(filepath):
			
			print "case #%d: time:%.02f" % (case_index, time.time() - start_time)
			result = calc_result(case)
			
			#######################
			#### format output ####
			#######################
			f_out.write("Case #%d: %s\n" % (case_index, result))
				
if __name__ == '__main__':
	main(sys.argv[1])
