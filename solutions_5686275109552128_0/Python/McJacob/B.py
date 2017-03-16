import sys

def main(input_file):
	number_of_cases = int(input_file.readline().strip("\n"))
	for case_number in xrange(1, number_of_cases + 1):
		print "Case #%d: %d" % (case_number, case(input_file, case_number))

def ceil_div(x, y):
	x = x + y - 1
	return x // y

def case(input_file, case_number):
	D = int(input_file.readline().strip("\n"))
	if D == 0:
		return 0
		
	diners = map(int, input_file.readline().strip("\n").split())

	minimums = [i + 1 for i in xrange(max(diners))]
	for diner in diners:
		minimums[0] += diner - 1
		for i in xrange(1, diner):
			minimums[i] += ceil_div(diner, i + 1) - 1
	
	return min(minimums)
	
if __name__ == '__main__':
	main(open(sys.argv[1]))


