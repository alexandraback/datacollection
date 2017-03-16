import sys

def main(input_file):
	number_of_cases = int(input_file.readline().strip("\n"))
	for case_number in xrange(1, number_of_cases + 1):
		print "Case #%d: %s" % (case_number, case(input_file, case_number))

def case(input_file, case_number):
	x, r, c = map(int, input_file.readline().strip("\n").split())
	
	if (x >= 7):
		return "RICHARD"
	if (x == 1):
		return "GABRIEL"
		
	if ((r * c) % x) != 0:
		return "RICHARD"
	if (x == 2):
		return "GABRIEL"
	
	if (r <= 1) or (c <= 1):
		return "RICHARD"
	if (x == 3):
		return "GABRIEL"
	
	if (r <= 2) or (c <= 2):
		return "RICHARD"
	if (x == 4):
		return "GABRIEL"

	if (r <= 3) or (c <= 3):
		return "RICHARD"

	return "GABRIEL"
	
if __name__ == '__main__':
	main(open(sys.argv[1]))


