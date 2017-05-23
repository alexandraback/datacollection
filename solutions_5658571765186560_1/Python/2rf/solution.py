import sys

def work(one_test):
	t = int(input())
	for i in range(1, t + 1):
		print("test {} started".format(i), file = sys.stderr)
		print("Case #{}: ".format(i), end = '')
		one_test()

def f(x, r, c):
	if r * c % x != 0:
		return False
	if r > c:
		r, c = c, r
	if x <= 2:
		return True
	elif x == 3:
		return r > 1
	elif x == 4:
		return r > 2
	elif x == 5:
		return r > 3
	elif x == 6:
		return r > 3
	else:
		return False

def one_test():
	x, r, c = map(int, input().split())
	print('GABRIEL' if f(x, r, c) else 'RICHARD')

work(one_test)
