import sys

def main(input_file):
	number_of_cases = int(input_file.readline().strip("\n"))
	for case_number in xrange(1, number_of_cases + 1):
		print "Case #%d: %s" % (case_number, case(input_file, case_number))

def case(input_file, case_number):
	next_line = input_file.readline().strip("\n").split()
	s_max = int(next_line[0])
	shyness_levels = next_line[1]
	
	extra_friends = 0
	total_audience = 0
	
	for shyness, amount in enumerate(shyness_levels):
		amount = int(amount)
		missing = shyness - total_audience
		if (amount > 0) and (missing > 0):
			extra_friends += missing
			total_audience += missing
		total_audience += amount
	
	return extra_friends
	
if __name__ == '__main__':
	main(open(sys.argv[1]))


