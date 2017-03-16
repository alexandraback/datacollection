from sys import stderr

for i in range(int(raw_input())):
	a, b = map(int, raw_input().split())
	
	stderr.write(str(i + 1) + '\n')
	
	r = 0
	for num in xrange(a, b + 1):
		num2 = str(num)
		rots = set()
		for rot in range(len(num2) - 1):
			num2 = num2[1:] + num2[0]
			num2i = int(num2)
			if num2i <= b and num2i > num:
				rots.add(num2i)
		r += len(rots)
	
	print 'Case #%d: %d' % (i + 1, r)
