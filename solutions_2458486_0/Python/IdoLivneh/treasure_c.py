import sys
import time
import itertools #use combinations!

def iterate_cases_1lpc(filepath):	#1lpc = 1 line per case
	with file(filepath, 'rb') as f_in:
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			yield line_index, line.strip().split(' ')

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
				assert len(line.strip().split(' ')) == 2
				K = int(line.strip().split(' ')[0])
				N = int(line.strip().split(' ')[1])
				lines_left = N + 1
				case = [K, N]
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
	
############################################################
#### add solution here 									####
#### don't forget to change data from str to int/float  ####
############################################################
class Chest(object):
	def __init__(self, code, keys):
		self.code = code
		self.keys = keys
		self.state = 'closed'
	def open(self):
		self.state = 'opened'
	def close(self):
		self.state = 'closed'
	def is_open(self):
		return self.state == 'opened'

def list_copy(list):
	a = []
	for elem in list:
		a.append(elem)
	return a
		
def solve(chests, my_keys, moves, hashes):
	N = len(chests)
	for index, chest in enumerate(chests):
		if chest.is_open():
			continue
		if my_keys.count(chest.code):
			moves.append(index)
			
			a = list_copy(moves)
			a.sort()
			hash_val = hash(str(a))
			if hashes.has_key(hash_val):
				moves.pop()
				continue
			
			hashes[hash_val] = 1
			chest.open()
			my_keys.remove(chest.code)
			my_keys.extend(chest.keys)
			
			result = solve(chests, my_keys, moves, hashes)
			
			if result == 'stuck':
				for key in chest.keys:
					my_keys.remove(key)
				my_keys.append(chest.code)
				chest.close()
				moves.pop()
				continue
			else:
				return result
	
	for chest in chests:
		if not chest.is_open():
			return 'stuck'
	return 'good'
		
def calc_result(case):

	print_flag = False

	#print "\t%s" % case
	K = int(case[0])
	N = int(case[1])
	my_keys = list_to_int(case[2])
	chests = []
	for index, chest_str in enumerate(case[3:]):
		code = int(chest_str[0])
		keys = list_to_int(chest_str[2:])
		new_chest = Chest(code, keys)
		chests.append(new_chest)
		if print_flag:
			print "\tchest %d->code:%d keys:%s" % (index + 1, code, keys)
	
	all_keys = list_copy(my_keys)
	all_codes = []
	for chest in chests:
		all_keys.extend(chest.keys)
		all_codes.append(chest.code)
	for code in all_codes:
		if all_codes.count(code) > all_keys.count(code):
			result = 'IMPOSSIBLE'
			print result
			print
			#raw_input()
			return result

	moves = []
	hashes = {}
	result = solve(chests, my_keys, moves, hashes)
	print result
	
	if result == 'stuck':
		result = 'IMPOSSIBLE'
		print result
		print
		#raw_input()
		return result
		
	result = ''
	for move in moves:
		result += "%d " % (move + 1)
	result = result[:-1]
	print result
	print
	#raw_input()
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
