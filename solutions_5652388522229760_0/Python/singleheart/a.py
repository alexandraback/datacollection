#!/usr/bin/python

T = input()
for t in range(1, T + 1):
	N = input()
	digits = [False] * 10

	result = "INSOMNIA"
	number = N
	for i in range(1, 200 + 1):
		#print number
		for digit in [int(c) for c in str(number)]:
			digits[digit] = True
		if digits == [True] * 10:
			result = number
			break
		number += N

	print "Case #%d: %s" % (t, result)
