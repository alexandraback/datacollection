from sys import stdin
from decimal import *

input = stdin.readlines()
getcontext().prec = 100

for i in range(1, 1+int(input[0])):
	line = input[i].split()
	r, t = int(line[0]), int(line[1])

	b = 2 * r - 1
	n = int((Decimal(-b) + Decimal(b * b + 8 * t) ** Decimal(0.5)) / Decimal(4))
	#n = int((-b + (b * b + 8 * t) ** .5) / 4) not precise

	print "Case #{0}: {1}".format(i, n)