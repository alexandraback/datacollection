def computeMin(initalMoteSize, motes, index):
	if len(motes) == 0 or index == len(motes):
		return 0
	elif initalMoteSize == 1:
		return len(motes) - index
	elif initalMoteSize <= motes[index]:
		return min(1 + computeMin(2*initalMoteSize - 1, motes, index), len(motes) - index)
	else:
		return min(computeMin(initalMoteSize + motes[index], motes, index + 1), len(motes) - index)

for i in xrange(input()):
	l  = raw_input()
	ims, mc = [int(token) for token in l.split()]
	l = raw_input()
	ms = sorted([int(token) for token in l.split()])
	print "Case #%d: %d" % (i + 1, computeMin(ims, ms, 0))