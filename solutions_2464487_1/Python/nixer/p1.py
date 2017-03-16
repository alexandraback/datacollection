from math import sqrt

x = int(raw_input())

for i in xrange(0,x):
	parts = [int(j) for j in raw_input().split()]
	a = (parts[0]+1) ** 2 - parts[0] ** 2 
	d = (parts[0]+3) ** 2 - (parts[0]+2) ** 2 - a

	bigval = ((d - 2*a) + sqrt((2*a - d) ** 2 + 8*d*parts[1])) / (2 * d)
	
	# float value
	# adjust it
	n = int(bigval)

	while (n * (2*a + (n-1)*d)) / 2 < parts[1]:
		n += 1

	while (n * (2*a + (n-1)*d)) / 2 > parts[1]:
		n -= 1


	print "Case #%d: %d" %  (i+1, n)
