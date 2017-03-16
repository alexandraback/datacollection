import sys

t = int(sys.stdin.readline())
for i in range(t):
	inputline = sys.stdin.readline().strip()
	inputparams = inputline.split()

	a = int(inputparams[0])
	b = int(inputparams[1])

	inputline = sys.stdin.readline().strip()
	inputparams = inputline.split()

	previous_expectation = b + 1
	all_correct_possibility = 1.0

	for j in range(a):
		p = float(inputparams[j])

		p1 = p * all_correct_possibility * (b - j) + (1 - p * all_correct_possibility) * (b - j + b + 1)
		p2 = 1 + previous_expectation
		p3 = (b + 2) if (j < b - 1) else (p * all_correct_possibility) * 1 + (1 - p * all_correct_possibility) * (b + 2)

		previous_expectation = min(p1, p2, p3)
		all_correct_possibility *= p

	print "Case #%d: %.6f" % (i + 1, previous_expectation)

