import sys
import time
import itertools #use combinations!
import random

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

def shorten(trains):
	res = []
	for train in trains:
		tmp_train = train
		for c in set(train):
			while True:
				if not c*2 in tmp_train: break
				tmp_train = tmp_train.replace(2*c,c)
		res.append(tmp_train)
	return res

def are_trains_valid(trains):
	for train in trains:
		if len(train) != len(set(train)):
			return False
	return True
	
def merge_trains(trains):
	res = []
	orig_trains = copy_list(trains)
	#print 'merge start:', trains
	while trains:
		train = trains[0]
		#print train, ':', 
		
		if len(train) == 1:
			#print 'len1'
			res.append(train)
			trains.remove(train)
			continue
		
		f = train[-1]
		if orig_trains.count(f) == 0:
			poss = []
			for elem in trains:
				if elem[0] == f and len(elem) > 1:
					poss.append(elem)
			
			if len(poss) > 1:
				'bad trains'
				return 0
			
			if poss:
				#print 'found:', train, poss[0], 'adding', ''.join([train,poss[0]])
				res.append(''.join([train,poss[0]]))
				trains.remove(train)
				trains.remove(poss[0])
				continue
		
		s = train[0]
		if orig_trains.count(s) == 0:
			poss = []
			for elem in trains:
				if elem[-1] == s and len(elem) > 1:
					poss.append(elem)
			
			if len(poss) > 1:
				'bad trains'
				return 0
			
			if poss:
				#print 'found:', train, poss[0], 'adding', ''.join([train,poss[0]])
				res.append(''.join([poss[0], train]))
				trains.remove(train)
				trains.remove(poss[0])
				continue
		
		#print 'nothing'
		res.append(train)
		trains.remove(train)
		
		
	return res

			
		

def solve(N, trains):
	res = None
	
	
	while True:
		trains = shorten(trains)
		print 'short:', trains
		
		if not are_trains_valid(trains):
			print 'bad'
			return 0
		
		if len(trains) == 1:
			break
		
		new_trains = merge_trains(copy_list(trains))
		if new_trains == trains:
			break
		trains = new_trains
		if new_trains == 0:
			return 0
		
		print 'merged:', trains
	
	print 'got to perms'
	count = 0
	for perm in itertools.permutations(trains):
		poss = ''.join(perm)
		is_ok = True
		for c in set(poss):
			tmp_poss = poss
			while True:
				if not c*2 in tmp_poss: break
				tmp_poss = tmp_poss.replace(2*c,c)
			if tmp_poss.count(c) > 1:
				is_ok = False
		if is_ok:
			count += 1
	
	return count
	
def calc_result(case):
	result = None
	
	N = int(case[0][0])
	trains = case[1]

	result = solve(N, trains)
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
		for case_index, case in iterate_cases_nlpc(filepath, 2):
			
			print "case #%d: time:%.02f" % (case_index, time.time() - start_time)
			result = calc_result(case)
			
			#######################
			#### format output ####
			#######################
			f_out.write("Case #%d: %s\n" % (case_index, result))
				
if __name__ == '__main__':
	main(sys.argv[1])
