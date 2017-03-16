T = int(raw_input())
for case in xrange(1, T+1):
	A, N = [int(x) for x in raw_input().split(' ')]
	motes = sorted([int(x) for x in raw_input().split( )])
	try_motes = []
	A1 = A
	trys = 0
	while len(motes) > 0:
		if (motes[0] < A):
			A = A + motes.pop(0)
			A1 = A	
		elif (A + A - 1 > motes[0]):
			A = 2 * A - 1
			trys = trys + 1
			A1 = A
		elif (len(try_motes) > 0 and try_motes[0] < A1):
			A1 = A1 + try_motes.pop(0)
			if (len(try_motes) == 0):
				A = A1
		else:
			A1 = 2 * A1 - 1
			try_motes.append(motes.pop(0))
			trys = trys + 1
	print "Case #{0}: {1}".format(case, trys)
