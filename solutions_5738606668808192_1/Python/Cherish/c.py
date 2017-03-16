print 'Case #1:'
s = ' '.join(map(str, [int(bin(1<<16|1)[2:], i) for i in range(2, 11)]))
for i in range(500):
	x = (i*2+(1<<15|1)) * (1<<16|1)
	print bin(x)[2:], s
