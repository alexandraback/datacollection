f = open('C-large.in')
T = int(f.readline())
for t in range(1, T+1):
	R, C, M = map(int, f.readline().split())
	print 'Case #%d:' % (t)
	if R == 1:
		#
		# Always possible
		# 
		print '*'*M + '.'*(C-M-1) + 'c'
		continue
	elif C == 1:
		#
		# Always possible
		#		
		solution = '*'*M + '.'*(R-M-1) + 'c'
		for s in solution:
			print s
		continue
	elif M == R*C - 1:
		#
		# Always possible
		#
		print 'c'+'*'*(C-1)
		for r in range(R-1):
			print '*'*C
		continue
	elif M == R*C-4:
		print 'c.' + '*'*(C-2)
		print '..' + '*'*(C-2)
		for i in range(2,R):
			print '*'*C
		continue

	if M == R*C-2 or M == R*C-3 or M == R*C-5 or M == R*C-7:
		print 'Impossible'
		continue

	#
	# R == 2 is problematic. If M is even, we can, otherwise we can't!
	#
	elif R == 2:
		if M % 2 == 0:
			print '*'*(M/2) + '.'*(C-M/2-1) + 'c'
			print '*'*(M/2) + '.'*(C-M/2)
		else:
			print 'Impossible'
		continue
	elif C == 2:
		if M % 2 == 0:
			s1 =  '*'*(M/2) + '.'*(R-M/2-1) + 'c'
			s2 = '*'*(M/2) + '.'*(R-M/2)
			for i in range(R):
				print s1[i]+s2[i]
		else:
			print 'Impossible'
		continue

	box_threshold = R*C-2*R-2*C+4
	if M <= box_threshold:
		rows = M / (C-2)
		cols = M % (C-2)
		for i in range(R):
			if i < R-rows-1:
				if i == 0:
					print 'c' + '.'*(C-1)
				else:
					print '.'*C
			elif i == R-rows-1:
				print '.'*(C-cols) + '*' *cols
			else:
				print '..' + '*'*(C-2)
		continue

	row_threshold = R*C-2*C-2
	if M <= row_threshold:
		excess = M - (box_threshold)
		rows = (excess+1)/2
		for i in range(R):
			if i < 2:
				if i == 0:
					print 'c' + '.'*(C-1)
				else:
					print '.'*C
			elif i == 2:
				if excess % 2 == 0: # If even
					print '..' + '*'*(C-2)
				else:
					print '...' + '*'*(C-3)
			elif i < R-rows:
				print '..' + '*'*(C-2)
			else:
				print '*'*C
		continue

	col_threshold = R*C-6
	if M <= col_threshold:
		excess = M - (row_threshold)		
		if excess % 2 == 0:
			cols = (excess-2)/2
		else:
			cols = (excess+1)/2
		for i in range(R):
			if i < 2:
				if i == 0:
					print 'c' + '.'*(C-cols-1) + '*'*cols
				else:
					print '.'*(C-cols) + '*'*cols
			elif i == 2:
				if excess % 2 == 0: # If even
					print '*'*C
				else:
					print '...' + '*'*(C-3)
			else:
				print '*'*C
		continue


