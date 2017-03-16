L = [[] for x in xrange(2000001)]

for i in xrange(2000001):
	num = str(i)
	l = len(num)
	for x in xrange(1, l):
		newnum = (num[x:] + num[0:x])
		cnum = int(newnum)
		if cnum > i:
			bSuc = True
			for f in L[i]:
				if f == cnum:
					bSuc = False
					break
			if bSuc == True:
				L[i].append(cnum)

print 'OK'
print L[191919]
while True:
	infile = open(raw_input(), 'r')
	outfile = open(raw_input(), 'w')
	line = int(infile.readline())
	for cc in xrange(line):
		e = infile.readline().split()
		cnt = 0
		e1 = int(e[0])
		e2 = int(e[1])+1
		for d in xrange(e1, e2):
			for f in L[d]:
				if f > d and f < e2:
					cnt = cnt + 1
		outfile.write('Case #%d: %d\n' % (cc+1, cnt))
	infile.close()
	outfile.close()
