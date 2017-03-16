print 'Case #1:'
s = ' '.join(map(str, [int(bin(257)[2:], i) for i in range(2, 11)]))
for i in range(50):
	x = (i*2+129) * 257
	print bin(x)[2:], s
