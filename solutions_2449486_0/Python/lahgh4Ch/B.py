def checkCells(cell, N, M):
	for row in range(N):
		for column in range(M):
			possibility = True
			for j in range(M):
				if cell[row][j] > cell[row][column]:
					possibility = False
					break
			if possibility == True:
				continue
			possibility = True
			for i in range(N):
				if cell[i][column] > cell[row][column]:
					possibility = False
					break
			if possibility == False:
				return 'NO'
	return 'YES'

T = int(raw_input())
for t in range(T):
	cell = []
	line = raw_input()
	N, M = line.split(' ')
	N = int(N)
	M = int(M)
	for row in range(N):
		line = raw_input()
		line = line.split(' ')
		for column in range(M):
			line[column] = int(line[column])
		cell.append(line)
	print 'Case #' + str(t + 1) + ':', checkCells(cell, N, M)
