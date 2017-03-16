import sys

filename = sys.argv[1]
f = open(filename, 'r')

numCases = int(f.readline())

for t in range(numCases):
	line = f.readline().strip().split(' ')
	R = int(line[0])
	C = int(line[1])
	M = int(line[2])
	print 'Case #'+str(t+1)+': '

	freeSpot = R*C - M
	#print freeSpot

	if R == 1 or C == 1:
		if R == C:
			print 'c'
		else:
			soln = 'c'
			soln = soln + '.'*(freeSpot-1) + '*'*M
			if R == 1:
				print soln
			else:
				for i in range(R):
					print soln[i]
	elif R == 2 or C == 2:
		if freeSpot == 1:
			for r in range(R-1):
				print '*'*C
			print '*'*(C-1)+'c'
		elif freeSpot < 4 or freeSpot%2 != 0:
			print 'Impossible'
		else:
			soln = [['c','.'],['.','.']]
			for i in range((freeSpot-4)/2):
				soln.append(['.','.'])
			for i in range(M/2):
				soln.append(['*','*'])

			if C == 2:
				for r in range(R):
					print ''.join(soln[r])
			else:
				for r in range(R):
					printStr = []
					for c in range(C):
						printStr.append(soln[c][r])
					print ''.join(printStr)
	else:
		soln = []
		if freeSpot == 1:
			for r in range(R-1):
				print '*'*C
			print '*'*(C-1)+'c'
		elif freeSpot < 4 or freeSpot == 5 or freeSpot == 7:
			print 'Impossible'
		elif freeSpot == 4:
			print 'c.'+'*'*(C-2)
			print '..'+'*'*(C-2)
			for r in range(R-2):
				print '*'*(C)
		elif freeSpot == 6:
			print 'c..'+'*'*(C-3)
			print '...'+'*'*(C-3)
			for r in range(R-2):
				print '*'*(C)
		elif freeSpot == 8:
			print 'c..'+'*'*(C-3)
			print '...'+'*'*(C-3)
			print '..*'+'*'*(C-3)
			for r in range(R-3):
				print '*'*(C)
		elif freeSpot == 9:
			print 'c..'+'*'*(C-3)
			print '...'+'*'*(C-3)
			print '...'+'*'*(C-3)
			for r in range(R-3):
				print '*'*(C)
		else:		
			possible = True	
			while M > 0:
				larger = max(R,C)
				smaller = min(R,C)
				
				if M >= smaller:
					if R == larger:
						soln.append(('*'*smaller,'r'))
						R = R-1
					else:
						soln.append(('*'*smaller,'c'))
						C = C-1
					M = M - smaller
				else:
					if (larger - M) > 1:
						#solved
						if R == larger:
							soln.append(('*'*M+'.'*(larger-M),'c'))
							C = C-1
						else:
							soln.append(('*'*M+'.'*(larger-M),'r'))
							R = R-1
						M = 0
					elif (smaller - 1) > 2:
						#solved
						if R == larger:
							soln.append(('*'*(larger-2)+'.'*2,'c'))
							soln.append(('*'+'.'*(smaller-2), 'r'))						
						else:
							soln.append(('*'*(larger-2)+'.'*2,'r'))
							soln.append(('*'+'.'*(smaller-2), 'c'))

						C = C-1	
						R = R-1
						M = 0
					else:
						#impossible
						possible = False
						break			

			if possible:
				printStr = []
				for r in range(R-1):
					printStr.append('.'*C)
				printStr.append('.'*(C-1)+'c')	

				while soln:
					curStr,isRow = soln.pop()

					if isRow == 'r':
						printStr = [curStr] + printStr						
					else:
						for i in range(len(printStr)):
							printStr[i] = curStr[i]+printStr[i]

				for line in printStr:
					print line

			else:
				print 'Impossible'








