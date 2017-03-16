
def get_digits(num):
	s = set()
	while num > 0:
		s.add(num % 10)
		num /= 10
	return s

def get_last_number(num):
	if num == 0:
		return "INSOMNIA"

	s = set()
	nn = 0

	while len(s) < 10:
		nn += num
		s.update(get_digits(nn))

	return nn

def main():
	num_tests = int(raw_input())
	for x in xrange(num_tests):
		num = int(raw_input())
		last_num = get_last_number(num)
		print "Case #%d: %s" % (x + 1, last_num)

main()