#!/usr/bin/python

def solve(number):
	#print "number: " + str(number)
	if 0 == number:
		return "INSOMNIA"
	
	numbers_not_seen = range(10)
	found = 0
	current_number = number
	while (True):

		for c in str(current_number):
			if int(c) in numbers_not_seen:
				numbers_not_seen.remove(int(c))
		if not numbers_not_seen:
			return current_number
		current_number += number

import sys
input_lines = open(sys.argv[1], "rt").readlines()
stripped_input_lines = [line.strip() for line in input_lines]
num_tests = int(input_lines[0])
#print num_tests

i=1
for line in stripped_input_lines[1:]:
	number = int(line)
	result = solve(number)
	print "Case #"+str(i)+": "+str(result)
	i+=1
