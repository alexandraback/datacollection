#input_set = "C-very-small.in"
#input_set = "C-small-check.in"
input_set = "C-large-check.in"
#input_set = "C-small-attempt0.in"

from math import sqrt
from itertools import count, islice
import random

def get_divider(n):
    if n < 2: 
    	return
    for number in count(2):
    	if 100000 < number or n < number**2:
    		return
        if n % number == 0:
            return number

def check_for_different_bases(n):
	result = []
	for base in xrange(2, 10 + 1):
		converted_candidate = int(n, base)
		divider = get_divider(converted_candidate)
		if divider is None:
			return None
		result.append(divider)
	return result

def generate_candidate(J, seed):
	random.seed(seed)
	return '1' + ''.join(random.choice('01') for x in xrange(J-2)) + '1'

def find_numbers(J, N):
	dividers = {}
	results = set()

	j = 0
	while len(results) < N:
		j += 1
		#print j
		candidate = generate_candidate(J, j)
		#print candidate
		result = check_for_different_bases(candidate)
		if result is None:
			continue
			#print "Fuck!"
		else:
			#print result
			results.add(candidate)
			dividers[candidate] = result
		#print candidate
	return dividers, results


with open(input_set) as cases:
	next(cases)
	J, N = (int (x) for x in next(cases).split())

	print "Case #1:"
	dividers, results = find_numbers(J, N)
	for result in results:
		print result, " ".join(str(x) for x in dividers[result])