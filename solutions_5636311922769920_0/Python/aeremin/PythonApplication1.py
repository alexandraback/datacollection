from numpy import base_repr
import math

def run_test():
	inp = input().split(' ')
	k = int(inp[0])
	c = int(inp[1])
	s = int(inp[2])
	needS = math.ceil(k / c)
	if (needS > s):
		return "IMPOSSIBLE"

	nums = []
	for i in range(needS):
		num = 1;
		for d in range(c):
			num += min(k - 1, i * c + d) * (k ** d)
		nums.append(str(num))

	return ' '.join(nums)


num_tests = int(input())
for i in range(1, num_tests + 1):
	print("Case #%i: %s" % (i, run_test()))