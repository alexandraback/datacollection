def run_test():
	n = int(input())
	if (not n):
		return "INSOMNIA"
	digits = set(['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'])
	for m in range(1, 100):
		digits.difference_update(set(str(m * n)))
		if (not digits):
			return str(m * n)

num_tests = int(input())
for i in range(1, num_tests + 1):
	print("Case #%i: %s" % (i, run_test()))