import sys

def work(one_test):
	t = int(input())
	for i in range(1, t + 1):
		print("test {} started".format(i), file = sys.stderr)
		print("Case #{}: ".format(i), end = '')
		one_test()