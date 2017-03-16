import sys
import time
import itertools #use combinations!
import random
import math
import heapq 	#use heapq.heapify(on list); 
				#use heapq.heappop(list) to continuously get the lowest

#in case you need this:
#sys.setrecursionlimit(8000)

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

def iterate_cases_subsections(filepath, num_of_subs):		#subsections - with subsections. first line in each gives the lines per subsection.
	with file(filepath, 'rb') as f_in:
		case_counter = 0
		new_case = True
		for line_index, line in enumerate(f_in):
			if line_index == 0: #T
				continue
			if new_case:
				new_case = False
				new_sub_case = True
				sub_cases_left = num_of_subs
				case_counter += 1
				case = []
			if new_sub_case:
				new_sub_case = False
				sub_case = []
				assert len(line.strip().split(' ')) == 1
				lines_left = int(line.strip())
				continue
			if lines_left:
				lines_left -= 1
				sub_case.append(line.strip().split(' '))
			if not lines_left:
				case.append(sub_case)
				sub_cases_left -= 1
				new_sub_case = True
				if not sub_cases_left:
					new_case = True
					yield case_counter, case
					
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
	res.extend(list)
	return res	

def gcd(a, b):
    """Calculate the Greatest Common Divisor of a and b.
    Unless b==0, the result will have the same sign as b (so that when
    b is divided by it, the result comes out positive).
    """
    while b:
        a, b = b, a%b
    return a

PRIMES_FILENAME = "prime.txt"
def get_primes(N):
	"""First create primes using 'python make_primes.py <N>'
	This will create prime.txt file in the same folder. move it to working folder.
	"""
	primes = []
	with file(PRIMES_FILENAME, 'rb') as f:
		for line in f.readlines():
			p = int(line.strip())
			if p > N:
				break
			primes.append(p)
		else:
			raise ValueError('Create a bigger prime file')
	return primes
			
def choice(a, b):
	"""This is a O(a) runtime a!/(a-b)!b! calc.
	It goes to lengths for keeping the result a small number.
	This assumes a>=b or assertion error will be raised.
	"""
	assert a >= b
	res = 1
	if b > a - b:
		for i in xrange(b + 1, a+1):
			res *= i
		for i in xrange(1, a-b+1):
			res /= i
	else:
		for i in xrange(a-b + 1, a+1):
			res *= i
		for i in xrange(1, b+1):
			res /= i
	return res
	
############################################################
#### add solution here 									####
#### don't forget to change data from str to int/float  ####
############################################################

def solve(a, b, pref_a, pref_b, memo):

	if not a:
		assert not b
		return (abs(int(pref_a) - int(pref_b)), int(pref_a), int(pref_b), pref_a, pref_b)

	options = []
	if not pref_a or (int(pref_a) == int(pref_b)):
		if a[0] == '?' and b[0] == '?':
			options.append(solve(a[1:], b[1:], pref_a + '0', pref_b + '0', memo))
			options.append(solve(a[1:], b[1:], pref_a + '0', pref_b + '1', memo))
			options.append(solve(a[1:], b[1:], pref_a + '1', pref_b + '0', memo))
			options.append(solve(a[1:], b[1:], pref_a + '1', pref_b + '1', memo))
		if a[0] == '?' and b[0] != '?':
			bb = int(b[0])
			if bb < 9:
				options.append(solve(a[1:], b[1:], pref_a + str(bb + 1), pref_b + b[0], memo))
			options.append(solve(a[1:], b[1:], pref_a + b[0], pref_b + b[0], memo))
			if bb > 0:
				options.append(solve(a[1:], b[1:], pref_a + str(bb - 1), pref_b + b[0], memo))
		if a[0] != '?' and b[0] == '?':
			aa = int(a[0])
			if aa < 9:
				options.append(solve(a[1:], b[1:], pref_a + a[0], pref_b + str(aa + 1), memo))
			options.append(solve(a[1:], b[1:], pref_a + a[0], pref_b + a[0], memo))
			if aa > 0:
				options.append(solve(a[1:], b[1:], pref_a + a[0], pref_b + str(aa - 1), memo))
		if a[0] != '?' and b[0] != '?':
			options.append(solve(a[1:], b[1:], pref_a + a[0], pref_b + b[0], memo))
	elif int(pref_a) > int(pref_b):
		if a[0] == '?' and b[0] == '?':
			options.append(solve(a[1:], b[1:], pref_a + '0', pref_b + '9', memo))
		if a[0] == '?' and b[0] != '?':
			options.append(solve(a[1:], b[1:], pref_a + '0', pref_b + b[0], memo))
		if a[0] != '?' and b[0] == '?':
			options.append(solve(a[1:], b[1:], pref_a + a[0], pref_b + '9', memo))
		if a[0] != '?' and b[0] != '?':
			options.append(solve(a[1:], b[1:], pref_a + a[0], pref_b + b[0], memo))
	elif int(pref_a) < int(pref_b):
		if a[0] == '?' and b[0] == '?':
			options.append(solve(a[1:], b[1:], pref_a + '9', pref_b + '0', memo))
		if a[0] == '?' and b[0] != '?':
			options.append(solve(a[1:], b[1:], pref_a + '9', pref_b + b[0], memo))
		if a[0] != '?' and b[0] == '?':
			options.append(solve(a[1:], b[1:], pref_a + a[0], pref_b + '0', memo))
		if a[0] != '?' and b[0] != '?':
			options.append(solve(a[1:], b[1:], pref_a + a[0], pref_b + b[0], memo))
	else:
		assert False
	options.sort()		
	return options[0]
		
def calc_result(case):
	result = None
	a, b = case
	print a, b
	
	memo = dict()
	output = solve(a, b, '', '', memo)
	
	result = '%s %s' % (output[3], output[4])
	print result
	return result
	

def main(filepath):
	# if needed, define global primes here and get it from file.
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
