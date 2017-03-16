from math import sqrt

def case(case_no):
	a, b = input().split()

	count = 0

	for i in range(int(a), int(b)+1):
		root = sqrt(i)
		if root != round(root):
			continue
		root = round(root)

		if str(i) == str(i)[::-1] and str(root) == str(root)[::-1]:
			count += 1

	print('Case #%i: %i' % (case_no, count))

for i in range(1, int(input())+1):
	case(i)