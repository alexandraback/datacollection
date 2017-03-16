import sys

num_cases = int(sys.stdin.readline())

def result(a):
	a = map(int,a.split(" "))
	height = a[0]
	width = a[1]
	boat = a[2]
	count = 0
	if (height == 1) and (width == boat):
		return str(boat)
	pos = boat
	while (pos <= width):
		count += 1
		pos += boat
	count *= height;
	if (boat == 1):
		return str(count)
	if ((width % boat) == 0):
		return str(count + (boat-1))
	return str(count + (boat))



for i in range(1,num_cases+1):
	print "Case #" + str(i) + ": " + result(sys.stdin.readline())
