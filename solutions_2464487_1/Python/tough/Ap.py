import math
import sys
import bisect
args = sys.stdin.read().split()
Cases = int(args[0])
args = args[1:]
for c in range(1, Cases + 1):
	r, t = int(args[0]), int(args[1])
	args = args[2:]
	a = 1
	b = 2000000000000111111
	while a < b:
		n = (a + b) // 2
		if 2 * n * r + 2 * n * (n+1) - 3 * n <= t:
			a = n+1
		else:
			b = n
	print("Case #{}: {}".format(c, a-1))