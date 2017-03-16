from numpy import base_repr
import math

def run_test():
	inp = input().split(' ')
	n = int(inp[0])
	j = int(inp[1])
	for a in range(j):
		halfBinary = 2 ** (int(n / 2) - 1) + 2 * a + 1
		halfBinaryStr = base_repr(halfBinary, 2)
		astr = 2 * halfBinaryStr
		for i in range(2, 11):
			astr = astr + " " + str(int(halfBinaryStr, i))
		print(astr)
	return ""


num_tests = int(input())
for i in range(1, num_tests + 1):
	print("Case #%i:" % i)
	run_test()