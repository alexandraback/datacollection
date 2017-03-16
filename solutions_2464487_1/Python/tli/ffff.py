import sys
import math

def val(N, r):
	return N * (2*N + 2 * r - 1)

n = int(sys.stdin.readline())
for i in range(n):
	x = sys.stdin.readline().split(" ")
	r = int(x[0])
	t = int(x[1])

	num_circles = int(0.25 * (math.sqrt(4 * r*r - 4 * r + 8*t + 1) - 2 * r + 1))

	if val(num_circles, r) == t:
		print "Case #" + str(i+1) + ": "+str(num_circles)				
	elif val(num_circles, r) < t:
		while val(num_circles+1, r) <= t:
			num_circles = num_circles + 1
		print "Case #" + str(i+1) + ": "+str(num_circles)
	elif val(num_circles, r) > t:
		while val(num_circles, r) > t:
			num_circles = num_circles - 1
		print "Case #" + str(i+1) + ": "+str(num_circles)
