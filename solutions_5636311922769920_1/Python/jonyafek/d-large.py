#!/usr/bin/python
def solve(k, c, s):
	#print "k: " + str(k)
	#print "c: " + str(c)
	#print "s: " + str(s)
	result = ""

	numbers_to_verify = range(1, k + 1)
	numbers_to_check = []
	while numbers_to_verify:
		number = 0
		for level in xrange(c):
			temp_num = 1
			if numbers_to_verify:
				temp_num = numbers_to_verify.pop()
			#print "temp_num: " + str(temp_num)
			#print "level: " + str(level)
			if 0 == level:
				level_value = temp_num
			else:
				level_value = (k ** level) * (temp_num - 1)
			#print "level value: " + str(level_value)
			number += level_value
			#print "number: " + str(number)
		numbers_to_check.append(number)
		#print "appended number: " + str(number)
		if len(numbers_to_check) > s:
			return "IMPOSSIBLE"

	for num in numbers_to_check:
		result += str(num) + " "

	return result.strip()

import sys
input_lines = open(sys.argv[1], "rt").readlines()
stripped_input_lines = [line.strip() for line in input_lines]
num_tests = int(input_lines[0])
#print num_tests

i=1
for line in stripped_input_lines[1:]:
	k = int(line.split()[0])
	c = int(line.split()[1])
	s = int(line.split()[2])
	result = solve(k, c, s)
	print "Case #" + str(i) + ": " + str(result)
	i += 1
