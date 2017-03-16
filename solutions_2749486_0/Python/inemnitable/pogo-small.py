t = int(raw_input())
for case in xrange(t):
	X, Y = (int(i) for i in raw_input().split())
	curr_x, curr_y = 0, 0
	moves = []
	movelength = 1
	while curr_x != X:
		if curr_x < X and X - curr_x >= movelength:
			curr_x += movelength
			moves.append('E')
		else:
			curr_x -= movelength
			moves.append('W')
		#print "x = " + str(curr_x)
		movelength += 1
	while curr_y != Y:
		if curr_y < Y and Y - curr_y >= movelength:
			curr_y += movelength
			moves.append('N')
		else:
			curr_y -= movelength
			moves.append('S')
		#print "y = " + str(curr_y)
		movelength += 1
	print "Case #" + str(case+1) + ": " + "".join(moves)
