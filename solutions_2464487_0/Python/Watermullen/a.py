

f = open("A-small-input.txt", "r")

T = int(f.readline().strip())

for test in range(1, T+1):
	r, t = map(int, f.readline().strip().split())

	a = 2
	b = 2*r-1
	c = -t
	n = int((-b + (b*b - 4*a*c)**0.5)/(2*a))

	if a*n*n + b*n + c > 0:
		n -= 1
	
		if a*n*n + b*n + c > 0:
			exit()

	print 'Case #{0}: {1}'.format(test, int(n))