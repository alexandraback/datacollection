import sys
T = int(raw_input())
for case in range(T):
	R, C, M = map(int, raw_input().split())
	non_mine = R * C - M
	short_side = min(R,C)
	long_side = max(R,C)
	if short_side == 1:
		if M < long_side:
			result = True
		else:
			result = False
	elif short_side == 2:
		if (M % 2 == 0) and (M / 2 <= (long_side - 2))  or R * C - 1 == M:
			result = True
		else:
			result = False
	else:
		if non_mine in [1, 4, 6, 8] or non_mine >= 9:
			result = True
		else:
			result = False
	print "Case #" + str(case+1) + ":"
	if result:
		if C == 1:
			for i in range(R):
				if M > 0:
					print '*'
					M -= 1
				elif i != R-1:
					print '.'
				else:
					print 'c'

		elif C == 2:
			for i in range(R):
				for j in range(C):
					if M > 0:
						sys.stdout.write('*')
						M -= 1
					elif i == R-1 and j == C-1:
						sys.stdout.write('c')
					else:
						sys.stdout.write('.')
				print ""
		elif R == 1:
			for i in range(C):
				if M > 0:
					sys.stdout.write('*')
					M -= 1
				elif i != C-1:
					sys.stdout.write('.')
				else:
					sys.stdout.write('c')
			print ""
		elif R == 2:
			for i in range(R):
				for j in range(C):
					if (M % 2 == 0 and M / 2 > j) or (M % 2 == 1 and (M / 2 > j or (M / 2 == j and i == 0))):
						sys.stdout.write('*')
					elif i == R-1 and j == C-1:
						sys.stdout.write('c')
					else:
						sys.stdout.write('.')
				print ""
		else:
			if non_mine == 1:
				for i in range(R):
					for j in range(C):
						if i == R-1 and j == C-1:
							sys.stdout.write('c')
						else:
							sys.stdout.write('*')
					print ""
			elif non_mine == 4:
				for i in range(R):
					for j in range(C):
						if R-2 <= i and i <= R-1 and C-2 <= j and j <= C-1:
							if i == R-1 and j == C-1:
								sys.stdout.write('c')
							else:
								sys.stdout.write('.')
						else:
							sys.stdout.write('*')
					print ""
			elif non_mine == 8:
				if R >= 3 and C >= 3:
					for i in range(R):
						for j in range(C):
							if R-3 <= i and i <= R-1 and C-3 <= j and j <= C-1:
								if i == R-1 and j == C-1:
									sys.stdout.write('c')
								elif i == R-3 and j == C-3:
									sys.stdout.write('*')
								else:
									sys.stdout.write('.')
							else:
								sys.stdout.write('*')
						print ""
				elif R >= 4:
					for i in range(R):
						for j in range(C):
							if R-4 <= i and i <= R-1 and C-2 <= j and j <= C-1:
								if i == R-1 and j == C-1:
									sys.stdout.write('c')
								else:
									sys.stdout.write('.')
							else:
								sys.stdout.write('*')
						print ""
				elif R >= 2 and C >= 4:
					for i in range(R):
						for j in range(C):
							if R-2 <= i and i <= R-1 and C-4 <= j and j <= C-1:
								if i == R-1 and j == C-1:
									sys.stdout.write('c')
								else:
									sys.stdout.write('.')
							else:
								sys.stdout.write('*')
						print ""


			else:
				for i in range(R):
					for j in range(C):
						if i < R-3:
							if M == 1 and j == C-2:
								sys.stdout.write('..')
								break
							elif M > 0:
								sys.stdout.write('*')
								M -= 1
							else:
								sys.stdout.write('.')
						elif i == R-3:
							if M == 1 and j == C-2:
								sys.stdout.write('..')
							elif M == 2 and j == C-3:
								sys.stdout.write('...')
								break
							elif M > 2 and M % 2 == 0 and j == C-3:
								sys.stdout.write('...')
								break
							elif M > 0:
								sys.stdout.write('*')
								M -= 1
							else:
								sys.stdout.write('.')
						elif i == R-2:
							if M / 2 > j:
								sys.stdout.write('*')
							else:
								sys.stdout.write('.')
						elif i == R-1:
							if M / 2 > j:
								sys.stdout.write('*')
							elif j == C-1:
								sys.stdout.write('c')
							else:
								sys.stdout.write('.')
					print ""
	else:
		print "Impossible"
