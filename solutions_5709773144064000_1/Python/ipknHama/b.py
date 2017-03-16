tn = input()
pn = 0
while tn:
	pn += 1
	tn -= 1
	print 'Case #%d:'%pn,
	C,F,X = [float(x) for x in raw_input().split()]
	base = 2
	T = X/base
	c = 0
	cT = 0
	while 1:
		cT += C/base
		c += 1
		base += F
		nT = X/base
		if nT + cT> T:
			break
		T = nT + cT
	print '%.10f' %T

