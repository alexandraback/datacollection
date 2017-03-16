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
				case = []
				assert len(line.strip().split(' ')) == 4
				case = list_to_int(line.strip().split(' '))
				lines_left = case[0]
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
def prod(arr):
	res = 1
	for elem in arr:
		res *= elem
	return res

def conjugate(combs, new_combs):
	res = {}
	for comb in combs.keys():
		if comb in new_combs.keys():
			res[comb] = combs[comb]
			res[comb][0] += new_combs[comb][0]
	return res

def calc_result(case):
	print "\t%s" % case
	R = case[0]
	N = case[1]
	M = case[2]
	K = case[3]
	guesses = case[4:]
	opts = []
	for i in xrange(2, M + 1):
		opts.extend([i] * N)
	print "opts: %s" % opts
	dict = {}
	sums = {}
	for comb in itertools.combinations(opts, N):
		if hash(comb) in dict:
			continue
		else:
			dict[hash(comb)] = 1
			for i in xrange(1, len(comb)+1):
				for sub_comb in itertools.combinations(comb,i):
					product = prod(sub_comb)
					sums.setdefault(product, {})
					sums[product].setdefault(hash(comb),[0, comb])
					sums[product][hash(comb)] = [sums[product][hash(comb)][0] + 1, comb]
	#for sum in sums:
	#	print "sum: %d, dict: %s" % (sum, sums[sum].values())
	
	#raw_input()
	
	res = []
			
	for guess in guesses:
		print "\t%s" % guess
		vals = list_to_int(guess)
		max_val = max(vals)
		if max_val == 1:
			for sum in sums:
				combs = sums[sum].values()[0]
				break
		else:			
			vals.remove(max_val)
			combs = sums[max_val]
			while vals:
				max_val = max(vals)
				vals.remove(max_val)
				if max_val == 1:
					continue
				new_combs = sums[max_val]
				combs = conjugate(combs, new_combs)
			combs = max(combs.values())
		
		print "\tcombs: %s" % combs
		res.append(combs[1])

	print "\tres: %s" % res
			
	return res

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
			f_out.write("Case #%d:\n" % case_index)
			for comb in result:
				st = ""
				for elem in comb:
					st += "%d" % elem
				f_out.write("%s\n" % st)
				
if __name__ == '__main__':
	main(sys.argv[1])
