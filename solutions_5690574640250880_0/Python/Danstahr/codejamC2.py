def check_fill(mines, plan):
	if mines == 0:
		return True
	if mines == 1:
		plan[2][2] = '*'
		return True
	return False

def onerow(columns, mines):
        return 'c' + (columns - mines - 1) * '.' + mines * '*'

def tworows(columns, mines):
	if (2 * columns == mines + 2 or (mines % 2 and 2 * columns - 1 != mines)):
		return None
	else:
		if mines == 2 * columns - 1:
			return ['c' + '*' * (columns - 1)] + ['*' * columns]
		else:
			string = ('.' * (columns - mines / 2) + '*' * (mines / 2)) 
			return ['c' + string[1:]] + [string]

def count(plan, i, j):
	drow = [-1, -1, -1, 0, 1, 1, 1, 0]
	dcol = [-1, 0, 1, 1, 1, 0, -1, -1]
	rows = len(plan)
	cols = len(plan[0])
	if plan[i][j] == '*':
		return
	plan[i][j] = 0
	for k in range(8):
		nrow = i + drow[k]
		ncol = j + dcol[k]
		if 0 <= nrow < rows and 0 <= ncol < cols and plan[nrow][ncol] == '*':
			plan[i][j] += 1
	plan[i][j] = str(plan[i][j])

def bfs(plan):
	q = [(0, 0)]
	solved = {}
	rows = len(plan)
        cols = len(plan[0])
	while q:
		item = q[0]
		q = q[1:]
		if item in solved:
			continue
		solved[item] = None
		count(plan, item[0], item[1])
		if plan[item[0]][item[1]] == '0':
			drow = [-1, -1, -1, 0, 1, 1, 1, 0]
        		dcol = [-1, 0, 1, 1, 1, 0, -1, -1]
			for k in range(8):
		                nrow = item[0] + drow[k] 
                		ncol = item[1] + dcol[k] 
				if 0 <= nrow < rows and 0 <= ncol < cols and plan[nrow][ncol] == '.':
					q.append((nrow, ncol))
					
		
			

def trivial_case(mines, plan):
	if mines == 1:
        	plan[2][2] = '*'
        	return True
        if mines == 2:
        	return False
        if mines == 3:
        	for i in range(3):
        		plan[2][i] = '*'
        	return True
        if mines == 4:
        	return False
        if mines == 5:
        	for i in range(3):
        		plan[2][i] = '*'
        		plan[i][2] = '*'
        	return True
        if mines == 6 or mines == 7:
        	return False
        if mines == 8:
        	for i in range(3):
        		for j in range(3):
        			if not (i == 0 and j == 0):
        				plan[i][j] = '*'
        	return True


cases = int(raw_input())

for case in range(1, cases + 1):
	R, C, M = map(int, raw_input().split())
	print "Case #%d:" % case
        if (R == 1):
                print onerow(C, M)
        elif (C == 1):
                print '\n'.join(onerow(R, M))
	elif R == 2:
		solution = tworows(C, M)
		if solution is not None:
			print '\n'.join(tworows(C, M))
		else:
			print "Impossible"
	elif C == 2:
		solution = tworows(R, M)
                if solution is not None:
			print '\n'.join(map(lambda x: ''.join(x), zip(*tworows(R, M))))
		else:
			print "Impossible"
	else:		
		plan = []
		valid = True
		for i in range(R):
			plan.append(['.'] * C)
		for i in reversed(range(2, R)):
			for j in reversed(range(2, C)):
				if M and (i != 2 or j != 2):
					plan[i][j] = '*'
					M -= 1
		if not check_fill(M, plan):
			for i in reversed(range(3, R)):
				if M >= 2:
					plan[i][0] = '*'
					plan[i][1] = '*'
					M -= 2
			if not check_fill(M, plan):
				for i in reversed(range(3, C)):
					if M >= 2:
						plan[0][i] = '*'
						plan[1][i] = '*'
						M -= 2
				if not check_fill(M, plan):
					valid = trivial_case(M, plan)	
		if valid:
			# bfs(plan)
			plan[0][0] = 'c'
			print '\n'.join(map(lambda x: ''.join(x), plan))
		else:
			print "Impossible"
