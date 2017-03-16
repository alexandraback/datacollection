for T in xrange(int(raw_input())):
	d = [int(i) for i in raw_input().split()]
	N = d[0]
	pts = d[1:]
	oldpts = pts[:]
	X = float(sum(pts))
	Xold = X
	goal = 2.*X/N
	print "Case #%d:" % (T+1),
	nums = sorted(list(set(pts)))
	for (i,currnum) in enumerate(nums):
		numtodo = pts.count(currnum)
		if currnum != nums[-1]:
			if (nums[i+1] - currnum) * numtodo > X:
				for j in xrange(len(pts)):
					if pts[j] == currnum:
						pts[j] += X / numtodo
				break
			else:
				for j in xrange(len(pts)):
					if pts[j] == currnum:
						pts[j] = nums[i+1]
				X -= (nums[i+1] - currnum) * numtodo
		else:
			for i in xrange(len(pts)):
				pts[i] += X / N
			break

	for i in xrange(N):
		print (pts[i] - oldpts[i]) / Xold * 100,
	print 

#	for i in pts:
#		if pts.count(i) < 3:
#			print max((2.*X/N - i) / X * 100, 0),
#		else:
#			print max((1.*X/N - i) / X * 100, 0),
