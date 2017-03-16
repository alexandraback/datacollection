import numpy as np
cases = int(raw_input())

for case in range(cases):
	r, c =  map(int, raw_input().strip().split())
	board = []
	done = False
	
	if (r==1) or (c==1):
		print "Case #"+str(case+1)+": YES"
		done = True
	for i in range(r):
		row = map(int, raw_input().strip().split())
		board.append(row)
	
	if (done): continue
	
	board=np.array(board)
	
	row_maxes = [max(board[i,:]) for i in range(r)]
	column_maxes = [max(board[:,i]) for i in range(c)]
	
	for i in range(r):
		if (done): break
		rmax = row_maxes[i]
		for j in range(c):
			# find min,pos in row
			cmax = column_maxes[j]
			#if (board[i][j]==cmax)or(board[i][j]==rmax):
			#	pass
			#	# still fine
			if (board[i][j]<cmax)and(board[i][j]<rmax):
				print "Case #"+str(case+1)+": NO"
				done = True
				break
		
			
	
	if (not done):
		print "Case #"+str(case+1)+": YES"
		done = True
