filename = 'A-large'
f = open(filename + '.in', 'r')
g = open(filename + '.out', 'w')

n = int(f.readline())
for i in xrange(0,n):
	g.write('Case #' + str(i+1) + ': ')
	line = map(int, f.readline().split('/'))
	ancestors = (2**40 * 1.0 * line[0]/line[1])
	if (ancestors % 1) != 0:
		g.write('impossible\n')
		continue
	for i in xrange(40, 0, -1):
		if ancestors >= 2**i:
			g.write(str(40-i) + '\n')
			break;

g.close()
f.close()