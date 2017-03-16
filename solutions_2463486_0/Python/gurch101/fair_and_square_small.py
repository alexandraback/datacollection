import math

num_test_cases = int(raw_input()) + 1

for num in xrange(1, num_test_cases):
	fs = 0
	a, b = [int(x) for x in raw_input().split()]
	while a <= b:
		a_str = str(a)
		if a_str == a_str[::-1]:
			a_sqrt = math.sqrt(a)
			if a_sqrt == long(a_sqrt):
				a_str = str(long(a_sqrt))
				if a_str == a_str[::-1]:
					fs = fs + 1
		a = a + 1
	print "Case #%s: %s" % (num, fs)