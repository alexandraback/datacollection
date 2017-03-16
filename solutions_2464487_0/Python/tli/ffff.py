import sys

def area(r):
	return (r+1)**2 - r**2

n = int(sys.stdin.readline())
for i in range(n):
	x = sys.stdin.readline().split(" ")
	r = int(x[0])
	t = int(x[1])

	num_circles = -1

	while t >= 0:
		t = t - area(r)
		r = r + 2
		num_circles = num_circles + 1

	print "Case #" + str(i+1) + ": "+str(num_circles)
