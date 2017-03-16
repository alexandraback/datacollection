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

def prod_to_value(prod, b):
	result = 0
	for index, dig in enumerate(reversed(prod)):
		if dig == 0:
			continue
		result += b ** (index + 1)
	return result
	
def is_prime(n):
	if n <= 3:
		return True
	for i in xrange(2, long(n**0.5) + 1):
		if not n % i:
			return False
	return True
	
def get_denominator(n, amount):
	result = []
	if n <= 3:
		return result
	for i in xrange(2, 10000):
		if not n % i:
			result.append(i)
			if len(result) == amount:
				return result
	return result

	
NUM_OF_DENOMINATORS = 10
	
def calc_result(case):
	result = ['']
	N, J = list_to_int(case)
	print N, J
	
	primes = {key: True for key in list_to_int(open('prime.txt', 'rb').readlines())}
	
	denoms = dict()
	for b in xrange(2, 11):
		print b,
		res = get_denominator(b**(N-1) + 1, NUM_OF_DENOMINATORS)
		print res
		denoms[b] = res
	print denoms
	
	count = 0
	for prod in itertools.product(*([(0,1)] * 14)):
		flag = True
		#print prod
		for b in range(2, 11):
			value = prod_to_value(prod, b)
			denominators = get_denominator(value, NUM_OF_DENOMINATORS)
			#print "\t", b, value, denominators
			if not any([den in denoms[b] for den in denominators]):
				flag = False
				break
		if not flag:
			continue
		#print 'yey'
		count += 1
		prod_string = '10000000000000000%s1' % ''.join([str(i) for i in prod])
		denominators = []
		for b in range(2, 11):
			dens = get_denominator(prod_to_value(prod, b), NUM_OF_DENOMINATORS)
			spec = [den for den in dens if den in denoms[b]][0]
			denominators.append(str(spec))
		result.append('%s %s' % (prod_string, ' '.join(denominators)))
		#print result[-1]
		if count == J:
			break
	return '\n'.join(result)
	
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
	print time.time() - start_time
				
if __name__ == '__main__':
	main(sys.argv[1])
