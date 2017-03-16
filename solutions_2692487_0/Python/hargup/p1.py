T = int(raw_input())
for i in range(T):
	A, N = [int(x) for x in raw_input().split()]
	mote_list = [int(x) for x in raw_input().split()]
	mote_list.sort()
	no_op = 0
	break_points = []#it will be a tuple of three (no_op after the double addition, no of double additions, n after double addition but before absorption)
	while N > 0:
		if A > mote_list[0]:
			A += mote_list[0]
			mote_list.pop(0)
			N = N -1
		elif (2*A - 1) > mote_list[0]:
			A = 2*A - 1 + mote_list[0]
			mote_list.pop(0)
			no_op += 1
			N = N -1
		else:
			no_dub_add = 0
			if A == 1:
				no_op += N
				break
			while A <= mote_list[0]:
				A = 2*A -1 
				no_dub_add += 1
				no_op += 1
			break_points += [(no_op, no_dub_add, N)]
			A += mote_list[0]
			mote_list.pop(0)
			N = N -1
	if len(break_points) != 0:
		min_op = no_op
		for point in break_points:
			op = point[0] - point[1] + point[2]
			if op < min_op:
				min_op = op
		no_op = min_op
	print "Case #%d: %d"%(i+1, no_op)
	
			 
	
	
