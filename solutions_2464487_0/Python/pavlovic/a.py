import math
import sys

b = int(sys.stdin.readline().strip())

for i in range(b):
	l = sys.stdin.readline().strip().split()
	r = int(l[0])
	t = int(l[1])

	k = int((1 - 2 * r) / 4.0 + math.sqrt(math.pow((2 * r - 1) / 4.0 , 2) + t / 2.0))


	res = (2 * r - 1) * k + 2 * k * k

	if (res > t):
		while (res > t):
			k -= 1
			res =  (2 * r - 1) * k + 2 * k * k
	elif (res <= t):
		while (res <= t):
			k += 1
			res =  (2 * r - 1) * k + 2 * k * k

		k -= 1

	print "Case #" + str(i + 1) + ": " + str(k)
