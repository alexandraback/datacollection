from math import *

T = input()

def pal(n):
	return str(n) == str(n)[::-1]

def sq(n):
	return int(sqrt(n)) == sqrt(n)

for case in range(T):
	x = raw_input().split()
	[a,b] = [int(y) for y in x]
	ct = 0
	for y in range(a, b+1):
		if pal(y) and sq(y) and pal(int(sqrt(y))):
			ct += 1

	print "Case #%d: %d" % (case + 1, ct)