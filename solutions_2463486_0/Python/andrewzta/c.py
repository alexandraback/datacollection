from bisect import *

def ispaly(t):
	return str(t) == str(t)[::-1]

good = []
x = 1
maxv = 10 ** 14
while True:
	y = int(str(x) + str(x)[::-1])
	if y * y > maxv:
		break
	if ispaly(y * y):
		good += [y * y]
	x += 1

x = 1
while True:
	y = int(str(x) + str(x)[::-1][1::])
	if y * y > maxv:
		break
	if ispaly(y * y):
		good += [y * y]
	x += 1

good.sort()

t = int(input())

for test in range(1, t + 1):
	a, b = [int(x) for x in input().split()]
	pa = bisect_left(good, a)
	pb = bisect_right(good, b)
	print("Case #" + str(test) + ": " + str(pb - pa))