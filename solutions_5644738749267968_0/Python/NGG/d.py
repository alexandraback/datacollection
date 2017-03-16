import sys
data = [line.split() for line in sys.stdin.readlines()]
tn = int(data[0][0])
for ti in xrange(tn):
	n = int(data[3*ti+1][0])
	a = map(lambda x: (float(x),0), data[3*ti+2])
	b = map(lambda x: (float(x),1), data[3*ti+3])
	rn = rd = cn = cd = 0
	for x in sorted(a+b):
		if x[1] == 0:
			cn = cn+1
			if cd > 0:
				cd = cd-1
				rd = rd+1
		else:
			cd = cd+1
			if cn > 0:
				cn = cn-1
				rn = rn+1
	print "Case #%d: %d %d" % (ti+1, rd, n-rn)

