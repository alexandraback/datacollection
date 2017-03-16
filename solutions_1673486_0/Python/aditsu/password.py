from sys import stdin
t = int(stdin.readline())
for i in range(t):
	line = stdin.readline().split()
	a = int(line[0])
	b = int(line[1])
	line = stdin.readline().split()
	p = [float(x) for x in line]
	p.append(0)
	c = 1
	best = b + 2
	for j in range(a + 1):
		t = b - a + 2 * (a - j) + 1
		t = t * c + (t + b + 1) * (1 - c)
		best = min(best, t)
		c *= p[j]
	print 'Case #' + str(i + 1) + ': ' + str(best)
