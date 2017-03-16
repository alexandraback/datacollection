#import math
import sys

def factorial(n):
	result = 1
	for i in xrange(1, abs(n)+1):
		result *= i
	if n >= 0:
		return result
	else:
		return -result

def binomial(n, k):
	if k < 0 or k > n:
		return 0.0
	if k == 0 or k == n:
		return 1.0
	return 1.0 * factorial(n) / (factorial(k) * factorial(n-k))

t = int(sys.stdin.readline().strip())

for i in range(t):
	l = sys.stdin.readline().strip().split()
	n = int(l[0])
	x = int(l[1])
	y = int(l[2])

	side_len = 1
	iteration = 1
	
	while n >= side_len * 2 - 1:
		n -= side_len * 2 - 1
		side_len += 2
		iteration += 1

	if ((x + y) / 2) < iteration - 1:
		probability = 1.0
	elif ((x + y) / 2) > iteration - 1:
		probability = 0.0
	else:
		if y == iteration:
			probability = 0.0
		elif n > side_len - 1 + y:
			probability = 1.0
		elif n <= y:
			probability = 0.0
		else:
			probability = 0.0
			for j in range(y + 1, n + 1):
				probability += binomial(n, j)
			probability /= (2 ** n)


	print "Case #" + str(i + 1) + ": " + ("%.6f" % probability)

