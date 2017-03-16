def run_test():
	s = input() + '+'
	return "%s" % (s.count("+-") + s.count("-+"))

num_tests = int(input())
for i in range(1, num_tests + 1):
	print("Case #%i: %s" % (i, run_test()))