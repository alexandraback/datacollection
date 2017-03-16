#!/usr/bin/python
def solve(stack, try_count):
	#print "stack: " + str(stack)
	#print "try_count: " + str(try_count)
	if not len(stack):
		return try_count
	
	if stack[0] == 1:
		return solve(stack[1:], try_count)

	if stack[-1] == -1:
		new_stack = [item * -1 for item in stack]
		return solve(new_stack, try_count + 1)
	else:
		count = 1
		while count < len(stack):
			count += 1
			if stack[-1 * count] == -1:
				break
		count -= 1
		#print "count: " + str(count)
		keep = stack[:(len(stack) - count)]
		flip = stack[(-1 * count):]
		flipped = [item * -1 for item in flip]
		#print "keep: " + str(keep)
		#print "flip: " + str(flip)
		#print "flipped: " + str(flipped)
		#print "keep + flipped: " + str(keep + flipped)
		return solve(keep + flipped, try_count + 1)

import sys
input_lines = open(sys.argv[1], "rt").readlines()
stripped_input_lines = [line.strip() for line in input_lines]
num_tests = int(input_lines[0])
#print num_tests

i=1
for line in stripped_input_lines[1:]:
	stack = []
	for c in line:
		num = -1 if c == "-" else 1
		stack.append(num)
	stack.reverse()
	result = solve(stack, 0)
	print "Case #"+str(i)+": "+str(result)
	i+=1
