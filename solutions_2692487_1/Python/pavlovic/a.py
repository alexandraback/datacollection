#import math
import sys

t = int(sys.stdin.readline().strip())

for i in range(t):
	l = sys.stdin.readline().strip().split()
	a = int(l[0])
	n = int(l[1])

	l = sys.stdin.readline().strip().split()
	m = []
	add_ops = []
	for j in range(n):
		m.append(int(l[j]))

	if a == 1:
		min_ops = n
	else:
		m.sort()

		ops = 0
		for j in range(n):
			while a <= m[j]:
				ops += 1
				a += a - 1

			a += m[j]

			add_ops.append(ops)


		min_ops = n
		for j in range(n):
			if add_ops[j] + n - j - 1 < min_ops:
				min_ops = add_ops[j] + n - j - 1

	print "Case #" + str(i + 1) + ": " + str(min_ops)
