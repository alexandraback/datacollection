from itertools import product
import sys
import re
num_cases = int(sys.stdin.readline())

def result(a,b,c):
	a = map(int,a.split())
	b = b.strip()
	c = c.strip()
	count = 0
	max_b = 0
	eaten = [0] * a[2]

	for test in product(b, repeat=a[2]):
		count += 1
		word = ''.join(test)
		b_eaten = int(len(re.findall("(?=" + c + ")", word)))

		if (b_eaten > 0):
			eaten[b_eaten-1] += 1
			if (b_eaten > max_b):
				max_b = b_eaten
	chance = 0.0
	for i in range(0,a[2]):
		chance += (i+1)*(float(eaten[i]) / count)

	return str(round(max_b-chance,6))


for i in range(1,num_cases+1):
	print "Case #" + str(i) + ": " + result(sys.stdin.readline(),sys.stdin.readline(),sys.stdin.readline())
