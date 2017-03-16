def solve(case_number):
	input_string = [s for s in raw_input()]
	output_string = input_string[0]
	for i in input_string[1:]:
		if i >= output_string[0]:
			output_string = i + output_string
		else:
			output_string = output_string + i

	print "Case #{}: {}".format(case_number, output_string)

t = int(raw_input())  # read a line with a single integer
for case in xrange(1, t + 1):
	solve(case)

'''
python solution.py <small.in> small.out
python solution.py <large.in> large.out
'''